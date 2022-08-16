// Naive approach: Generate all subarrays by keeping 2 for loops i & j and keeping sum from i to j and updating length if anytime sum reaches 0
// Time complexity:O(N*N); Space complexity:O(1)

// Optimised approach: Use a hashmap to store Sum of array upto that point and it's index. If at any point of time in traversing we reach the same sum as ever before(which is stored in the hashmap) we calculate length and update maxlength
// Time complexity:O(N); Space complexity:O(N)

#include<bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr){

    unordered_map<int,int> ourMap;
    
    int sum=0;

    int length=0;
    int maxLength=0;

    ourMap[0]=0;

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(ourMap.count(sum)){
            length=i-(ourMap[sum])+1;
            maxLength=max(length,maxLength);
        }else{
            ourMap[sum]=i+1;
        }
    }
return maxLength;
}