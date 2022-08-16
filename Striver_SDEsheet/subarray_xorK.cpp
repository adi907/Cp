// Naive approach: Find all subarrays possible and compare their xorsum with k. Increment count and return
// Time complexity: O(N*N); Space complexity: O(1)


// Optimised approach: for something to have xorsum equal to k is either xorsum upto that point leads to it or there needs to be a y(preceeding k) equal to xorsum^k(xorsum nullifies k part leaving y); no. of times that y occurs is no. of times k occurs
// Time complexity: O(N or NlogN{in c++ hashmap insertion can take logN in case of multiple collisiions}); Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x){
    int xorsum=0;
    int count=0;

    unordered_map<int,int> ourMap;

    int y;

    for(int i=0;i<arr.size();i++){
        xorsum=xorsum^arr[i];
        if(xorsum==x){
            count++;
        }

        y=xorsum^x;
        if(ourMap.count(y)){
            count+=ourMap[y];
        }
        ourMap[xorsum]++;//always do this at end bcz it can alter count of y(in edge case of when all elements equal to 0, target=0 and we also initialise xorsum with 0)
    }
return count;
}