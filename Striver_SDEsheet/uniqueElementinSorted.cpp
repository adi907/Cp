// Approach: Iterate over the array & find when 2 adjacent elements arent the same / xorsum all elements. resultant is answer
// Time complexity: O(N)  ; Space complexity: O(1)

// Approach: Before unique element, all duplicate elements occur on (even,odd)indices. After unique, all occur on (odd,even)indices. Find this breakpt. via Binary search. Return low(as it ends up just after breakpt. higher than high)
// Time complexity: O(logN) ; Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int uniqueElement(vector<int> nums, int n){
	int low=0;
    int high=nums.size()-2;//not the last element but 2nd last cuz if last element unique then low will go out of bounds at breakpt.
    int mid;

    // while(low<=high){
    //     mid=(low+high)/2;
    //     if(mid%2==0){//mid is even
    //         if(nums[mid]==nums[mid+1]){//left half
    //             low=mid+1;
    //         }else{//right half
    //             high=mid-1;
    //         }
    //     }else{//mid is odd
    //         if(nums[mid]==nums[mid+1]){//right half
    //             high=mid-1;
    //         }else{//left half
    //             low=mid+1;
    //         }
    //     }
    // }

//BETTER WAY
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==nums[mid^1]){//odd index gives smaller even ind. & even ind. gives bigger odd ind.->CHECKS FOR LEFT HALF
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

return nums[low];
}
