// Naive approach: Do 2 for loops. Traverse j for each i and check if condition satisfied increase the count
// Time complexity: O(N*N); Space complexity:O(1)


// Optimal approach: Do merge sort manually, but while merging->just before merging compare both split arrays and keep count of how many times arr[i]>2*arr[j]{keep incrementing j as both arrays sorted in themselves so when condition satisfied all left in left split array will also satisfy. So check other right split element}
// Time complexity: O(NlogN+N+N){dividing+merging+doing j-check operation(not n1*n2 as we keep j updated and at max n1+n2=N)}; Space complexity:O(N){total space req. for merging(2 temp. arrays)}

#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr,int low,int mid,int high){
    int count=0;
    int x=mid+1;
    for(int i=low;i<=mid;i++){
        while(x<=high && arr[i]>(2*arr[x])){
            x++;
        }
        count+=x-(mid+1);
    }
    
    int n1=mid-low+1;
    int n2=high-mid;
    
    int a[n1];
    int b[n2];
    
    for(int i=0;i<n1;i++){
        a[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    
    int i=0;int j=0;int k=low;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;k++;
        }else{
            arr[k]=b[j];
            j++;k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;j++;
    }
return count;
}

int mergeSort(vector<int>& arr,int low,int high){
    int pair=0;
    if(low<high){
        int mid=(low+high)/2;
        pair+=mergeSort(arr,low,mid);
        pair+=mergeSort(arr,mid+1,high);
        pair+=merge(arr,low,mid,high);
    }
return pair;
}

int reversePairs(vector<int> &arr, int n){
    return mergeSort(arr,0,n-1);
}

