// Naive approach: Sort the array. Iterate the array to find largest consecutive subsequence(ignore duplicate elements)
// Time complexity: O(NlogN + N); Space complexity: O(N){if you aren't allowed to sort given data set and need to sort the data in a new array; otherwise O(1)}

// Optimal approach: Use Hashsets(ordered set) which only stores unique elements and sorts them itself. Then iterate over the array and find largest consecutive subsequence
// Time complexity: O(N+N); Space complexity:O(N)
#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(!nums.size()){
        return 0;
    }
    set<int> s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    
    int count=1;
    int maxCount=1;
    
    for(auto i=s.begin();i!=s.end();i++){
        if(s.count(*i+1)){
            count++;
            maxCount=max(count,maxCount);
        }else{
            count=1;
        }
    }
return maxCount;
}

// ALTERNATIVE(works even better idk how): Use a hashmap

int longestConsecutive(vector<int>& nums) {
    if(!nums.size()){
        return 0;
    }
    unordered_map<int,int> ourMap;
    for(int i=0;i<nums.size();i++){
        if(!ourMap.count(nums[i])){
            ourMap[nums[i]]++;     
        }
    }
    
    int count=1;
    int maxCount=1;
    
    for(int i=0;i<nums.size();i++){
        if(!ourMap.count(nums[i]-1) && ourMap.count(nums[i]+1)){
            int j=1;
            while(ourMap.count(nums[i]+j)){
                count++;
                ourMap.erase(nums[i]+j);
                j++;
                
            }
            maxCount=max(count,maxCount);
            count=1;
        }
    }
return maxCount;
}