// Naive Approach: Store all elements in 1d array. sort it and return mid element
// Time complexity: O(N*M * log(N*M)) ; Space complexity: O(N*M)

#include<bits/stdc++.h>
using namespace std;

/*
int getMedian(vector<vector<int>> &matrix){
    vector<int> ans;

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();i++){
            ans.push_back(matrix[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    int key=ans[ans.size()/2]; 
return key;
}
*/

// Approach: keep applying binary search(on basis of how many elements is our element greater than) until finding break point then return low
// Time complexity: O() ; Space complexity: O()

int binSearch(vector<int> arr,int key){
    // find elements less/equal to key -> find index of element immediately greater than key
    int low=0;
    int high=arr.size()-1;
    int mid;

    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<=key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
return low;
}

int greaterThan(vector<vector<int>>arr,int key){
    int count=0;
    for(int i=0;i<arr.size();i++){
        count+=binSearch(arr[i],key);
    }
return count;
}

int getMedian(vector<vector<int>> &matrix){
    int low=1;
    int high=1e+5;

    int mid;
    int n=matrix.size()*matrix[0].size();
    int nums;

    while(low<=high){
        mid=(low+high)/2;
        nums=greaterThan(matrix,mid);
        if(nums<=(n/2)){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
return low;
}