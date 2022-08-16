// Naive approach: Run 2 nested for loops. Check whenever sum of arr[i]+arr[j]==target return answer
// Time complexity: O(N*N); Space complexity: O(1)

// Better approach: Sort array. 2pointers, start & end, each time compare arr[start]+arr[end] with target. Change start and end accordingly
// Time complexity: O(NlogN+N); Space complexity: O(1)

//this one also works in case of multiple solutions
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    
    int i=0;int j=arr.size()-1;
    
    while(i<j){
        if(arr[i]+arr[j]==s){
            vector<int>sol;
            int j1=j;
            while(arr[i]+arr[j1]==s && j1>i){
                sol.push_back(arr[i]);
                sol.push_back(arr[j1]);
                result.push_back(sol);
                j1--;
            }
            i++;
        }else if(arr[i]+arr[j]<s){
            i++;
        }else{
            j--;
        }
    }
    
return result;
}

// Optimal approach: Use Hashmaps to store all elements with their respective positions in array{take care of edge case when same element at same position is tried}
// Time complexity: O(N+N); Space complexity: O(N)

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> ourMap;
    for(int i=0;i<nums.size();i++){
        ourMap[nums[i]]=i;
    }
    
    vector<int>result;
    
    for(int i=0;i<nums.size();i++){
        int search=target-nums[i];
        if(ourMap.count(search)>0 && ourMap[search]!=i){
            result.push_back(i);
            result.push_back(ourMap[search]);
            return result;
        }
    }
return result;
}