// Naive approach: Iterate over array and count frequency of each element. If > than n/2 return answer
// Time complexity: O(N*N); Space complexity:O(1)

// Better approach: Use Hashmaps to store key-value pair. When value of an element exceeds n/2 return answer
// Time complexity: O(N TO NlogN{if many collisions}); Space complexity:O(N)

// Optimal approach(Moore's voting algo): Start iterating array, keep a target element and keep its count. If current element=target,count+=1;else count-=1. When count gets low to 0, change target element to whatever the current element is. The final target element will be the majority element.{run a check loop to ensure that final target element is infact in majority;else return -1} 
// Time complexity: O(N); Space complexity:O(1)

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count=0;
    int ans;

    for(int i=0;i<nums.size();i++){        
        if(count==0){
            ans=nums[i];
            count=1;
        }else if(nums[i]==ans){
            count++;
        }else{
            count--;
        }
    }//can change the order of if and else if(as no danger of reinitialization as only 1 majority element)
return ans;

    /* When it is given that there might not always be a majority element-> check*/

    // int checkCount=0;
    // for(int i=0;i<nums.size();i++){
    //     if(nums[i]==ans){
    //         checkCount++;
    //     }
    // }
    
    // if(checkCount>(nums.size()/2)){
    //     return ans;
    // }else{
    //     return -1;
    // }
}