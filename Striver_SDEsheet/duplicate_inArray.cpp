// Naive approach: Sort the array. Then traverse from start. If arr[i]=arr[i+1], return arr[i]
// Time complexity:O(NlogN+N) ; Space complexity: O(1)

// Better approach:Use boolean frequency array. As iterating through array;for each arr[i], mark the freq[arr[i]] with true. If any element already true; return it
// Time complexity:O(N) ; Space complexity:O(N)

// Optimised approach{but modifies the array}: Use Linked list cycle method(not actual linked list). Start from index=0, keep moving where value of index is.arr[0]-> arr[arr[0]]->arr[arr[0]]-> ... Keep marking travelled positions with -1. And when you reach a place which already has -1.Stop and return the subsequent value which led you to it
// Time complexity:O(N) ; Space complexity:O(1)
// Problem: Interviewer doesn't like manipulation to data set
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int start=0;
    while(1){
        if(arr[start]==-1){
            return start;
        }else{
           int temp=arr[start];
           arr[start]=-1;
           start=temp;
        }
    }
}

// Optimal approach(Hare & turtle method): Hare moves 2x the speed of turtle. Initialise both at start. When hare=turtle, set hare back to 0 and also make its speed equal to turtle. Then let them collide again. That point is the duplicate element.{see explaination in video}
// Time complexity:O(N) ; Space complexity:O(1)

int findDuplicate(vector<int>& nums) {
        int turtle=0;
        int hare=0;
        
        do{
            turtle=nums[turtle];
            hare=nums[nums[hare]];
        }while(turtle!=hare);
        
        hare=0;
        
        do{
            turtle=nums[turtle];
            hare=nums[hare];
        }while(turtle!=hare);
        
    return turtle;
}
