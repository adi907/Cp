// Naive approach: Simply search all elements of the 2d array
// Time complexity: O(N*M); Space complexity:O(1)

// Better approach: Traverse each row and apply binary search on each row to find target element
// Time complexity: O(N*logM); Space complexity:O(1)
#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>>& matrix,int target){
    int m=matrix.size();
    int n=matrix[0].size();

    int i=0;
    int j=n-1;
    while(i<m && j>=0){
        if(matrix[i][j]==target){
            return true;
        }
        if(matrix[i][j]>target){
            j--;
        }else{
            i++;
        }
    }
return false;
}


// Approach: As the 2d array is sorted both in row & column wise, we can assume the 2d array to be a linear 1d array. Just keep finding the mid element value acc. to 1d array, convert it into 2d array coordinates(row= divide by no. of columns, column=modulo by no. of columns), then keep adjusting low and high acc. to it. Traverse until low<=high otherwise return false
// Time complexity: O(log(N*M)); Space complexity:O(1)


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size();
    int n=matrix[0].size();
    
    int low=0;
    int high=(m*n)-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        int ele=matrix[mid/n][mid%n];
        
        if(ele>target){
            high=mid-1;
        }else if(ele<target){
            low=mid+1;
        }else{
            return true;
        }
    }
return false;
}