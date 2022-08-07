#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif

    int n;
    cin>>n;
    // const int N=1e6;
    int arr[100];
    int ans[100]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]<=0){
            continue;
        }else{
            ans[arr[i]-1]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i]!=1){
            cout<<i+1;
            return 0;   
        }
    }
return 0;
}
