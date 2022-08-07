#include<bits/stdc++.h>
using namespace std;

// Optimised approach: Gap Method
// Time complexity: O(NlogN); Space complexity: O(1);

void merge(vector<int>& arr1,vector<int>& arr2,int m,int n){

    int gap=ceil((float)(m+n)/2);
    int i,j;

    while(gap>=1){
        i=0;
        j=gap;

        while(j<m+n){
            if(j<m && arr1[i]>arr1[j]){
                swap(arr1[i],arr1[j]);
            }else if(j>=m && i<m && arr1[i]>arr2[j-m]){
                swap(arr1[i],arr2[j-m]);
            }else if(j>=m && i>=m && arr2[i-m]>arr2[j-m]){
                swap(arr2[i-m],arr2[j-m]);
            }
            i++;j++;
        }
        if(gap==1){
            break;
        }else{
            gap=ceil((float)(gap)/2);
        }
    }

    for(int i=0;i<n;i++){
        arr1[m]=arr2[i];
        m++;
    }
}



// My approach:
void merger(vector<int>& arr1,vector<int>& arr2,int m,int n){
    for(int i=0;i<n;i++){
        arr1[m]=arr2[i];
        m++;
    }
    sort(arr1.begin(),arr1.begin()+m);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int m,n;
    cin>>m>>n;

    vector<int>arr1;
    vector<int>arr2;

    int ele;

    for(int i=0;i<m+n;i++){
        cin>>ele;
        arr1.push_back(ele);
    }
    for(int i=0;i<n;i++){
        cin>>ele;
        arr2.push_back(ele);
    }
    
    merge(arr1,arr2,m,n);

    for(int i=0;i<m+n;i++){
        cout<<arr1[i]<<" ";
    }

    
return 0;
}