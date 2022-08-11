// Naive approach: Iterate over numsay and count frequency of each element. If > than n/3 return answer
// Time complexity: O(N*N); Space complexity:O(1)

// Better approach: Use Hashmaps to store key-value pair. When value of an element exceeds n/3 return answer
// Time complexity: O(N TO NlogN{if many collisions}); Space complexity:O(N)

// Optimal approach(Moore's voting algo): Iterate over the numsay. Keep 2 target elements{as there can be max 2 majority elements}. If the current element==any of 2 target elements, increase resp. count. else decrease count of both. If any of the 2's count gets down to 0, reintialise target element to current element and increment its count to 1. Final target elements need to be checked if they are in majority.
// Time complexity: O(N); Space complexity:O(1)

#include <bits/stdc++.h> 
using namespace std;

vector<int> majorityElementII(vector<int> &nums){
    int count1=0;
    int count2=0;
    
    int ans1=INT_MIN;
    int ans2=INT_MIN;

    for(int i=0;i<nums.size();i++){
        if(nums[i]==ans1){
            count1++;
        }else if(nums[i]==ans2){
            count2++;
        }else if(count1==0){
            ans1=nums[i];
            count1=1;
        }else if(count2==0){
            ans2=nums[i];
            count2=1;
        }else{
            count1--;count2--;
        }
    }//keep order of if's and else if's in same way(bcz if different order, danger of reinitialization by same element; say ans1 and ans2 will be same element)
    
    //check if both majority or not
    int cc1=0;
    int cc2=0;
    
    for(int i=0;i<nums.size();i++){
        if(nums[i]==ans1){
            cc1++;
        }
        if(nums[i]==ans2){
            cc2++;
        }
    }
    vector<int> result;
    
    if(cc1>nums.size()/3){
        result.push_back(ans1);
    }
    if(cc2>nums.size()/3){
        result.push_back(ans2);
    }

return result;
}