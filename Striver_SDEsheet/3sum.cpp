// Naive approach: Use 3for-loops for 3pointers i,j,k. Scan all possible triplets. See if any gives desired results(also take care of unique triplets so each time increment i,j,k to another unique element)
// Time complexity: O(N^3) ; Space complexity: O(3*K) {the extra sol vector that was required to push into res vector}

// Optimized approach: Insert all elements in a hashmap.Use 2for-loops for pointers i,j. Use hashmap to search for new target(keep check if element is of a different index and reduce its count so that a different index same element can form a triplet)
// Time complexity: O(N^2*logM) {logM is worst case for hashmap}; Space complexity: O(N+ 3*K)

// Optimal appraoch: Sort the vector. Use 1 for loop and then 2pointer method(low & high) to check for the new target(also take care of unique triplets so each time increment i,low,high to another unique element OR just use SET data structure to eliminate that problem)
// Time complexity: O(N^2) ; Space complexity: O(3*K) {the extra sol vector that was required to push into res vector}

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int k){
	vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    
    int target;
    int low,high;
    
    int i=0;
    int key;
    
    while(i<arr.size()-2){
        target=k-arr[i];
        low=i+1;high=arr.size()-1;
        
        while(low<high){
            if(arr[low]+arr[high]==target){
                vector<int>sol;
                sol={arr[i],arr[low],arr[high]};
                res.push_back(sol);
                
                do{
                    key=arr[low];
                    low++;    
                }while(arr[low]==key && low<high);
                
                do{
                    key=arr[high];
                    high--;
                }while(arr[high]==key && low<high);
            }else if(arr[low]+arr[high]<target){
                do{
                    key=arr[low];
                    low++;    
                }while(arr[low]==key && low<high);
            }else{
                do{
                    key=arr[high];
                    high--;
                }while(arr[high]==key && low<high);
            }
        }
        do{
            key=arr[i];
            i++;
        }while(arr[i]==key && i<arr.size()-2);
    }
return res;
}