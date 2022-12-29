// Approach: sorted matrix is rotated @1 point. So we know wherever we are at least 1side will be sorted. On basis of that sorted side, we take decision where our target will be
// Time complexity: O(logN) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low=0;
    int high=nums.size()-1;
    int mid;

    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[low]<=nums[mid]){//left side is sorted
            if(target>=nums[low] && target<nums[mid]){   //target present in left sorted side
                high=mid-1;
            }else{                                       //target present in unsorted right side
                low=mid+1;
            }
        }else{//right side is sorted
            if(target>nums[mid] && target<=nums[high]){  //target present in right sorted side
                low=mid+1;
            }else{                                       //target present in unsorted left side
                high=mid-1;
            }
        }   
    }
return -1;
}