// Approach: Do merge sort, but while merging whenver you need to place element of 2nd split array into main array, increase the count with all numbers left in 1st split array
// Time complexity: O(NlogN); Space complexity: O(N)
// Problem: Modifies the input array(can take another dummy array to store actual values-> increase space complexity to O(2N))

#include<bits/stdc++.h>
using namespace std;

long long merge(long long int* arr,int low,int mid,int high){
    long long int count=0;

    int n1=mid-low+1;
    int n2=high-mid;//high-(mid+1)+1=high-mid

    long long int a[n1];
    long long int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=low;

    while(i<n1 && j<n2){
        if(a[i]>b[j]){
            arr[k]=b[j];
            j++;k++;
            count+=n1-i;
        }else{
            arr[k]=a[i];
            i++;k++;
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

long long mergeSort(long long int* arr,int low,int high){
    long long int count=0;
    int mid=(low+high)/2;
    if(low<high){
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);

        count+=merge(arr,low,mid,high);
    }
return count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Unsorted array:\t";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }cout<<endl;

    //write code here for merge sort
    
    cout<<getInversions(arr,n)<<endl;

    cout<<"Sorted array:\t";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
return 0;
}