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
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=0;
    int record=0;
    if(n==1){
        cout<<"1";
        return 0;
    }

    for(int i=0;i<n-1;i++){
        if(arr[i]>max && arr[i]>arr[i+1]){
            max=arr[i];
            record++;
            
        }
    }
    if(arr[n-1]>max){
        record++;
    }
    cout<<record;
return 0;
}
