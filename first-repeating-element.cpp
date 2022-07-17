#include<iostream>
#include<climits>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif

    int n;
    const int N=1e6+2;
    int arr[N];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=INT_MAX;
    for(int i=0;i<n-1;i++){
        int key=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]==key){
                ans=min(ans,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]==arr[ans]){
            cout<<i;
            break;
        }
    }
return 0;
}
