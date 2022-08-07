// Brute force: Sort the array
// Time complexity: O(NlogN); Space complexity:O(1)

// Better approach: Count sort(count frequencies of all 0,1,2 then insert those many no. of 0,1 and 2)
// Time complexity: O(N+N); Space complexity: O(1)

// Optimised Approach(DNF sort): keep a low,mid and high pointers in array{where low and mid point at start and high points at end}{mid also used as an iterator to keep track of current element}. Keep traversing until mid<=high such that all elements before low are 0. all between low and high are 1. and all after high are 2
// Time complexity: O(N); Space complexity: O(1)

#include <bits/stdc++.h> 
using namespace std;

void swap(int* arr,int x,int y){
    int temp=arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}

void sort012(int *arr, int n){
    int low=0;
    int mid=0;
    int high=n-1;
    
    while(mid<=high){
        if(arr[mid]==0){
           swap(arr,mid,low);
            mid++;low++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr,high,mid);
            high--;
        }
    }
}