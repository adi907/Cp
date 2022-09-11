// Optimal approach: Just iterate the array. Keep increasing count as u encounter 1's and updating maxCount. If encounter 0 anytime, reset count back to 0
// Time complexity: O(N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount=0;
    int count=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
            maxCount=max(count,maxCount);
        }else{
            count=0;
        }
    }
return maxCount;
}