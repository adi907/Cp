//Find the maximum length up to which common difference of array elements is same

#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif

    int n;
    cin>>n;
    int arr[100];
    int ans[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        ans[i]=arr[i]-arr[i+1];
    }
    int count=0;
    int max=0;
    for(int i=0;i<n-1;i++){
        while(ans[i]==ans[i+1]){
            count++;
            i++;
        }
        max=count;
    }
    cout<<max+1;
return 0;
}
