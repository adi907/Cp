#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif

    int n,s;
    int arr[100];
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==s){
                cout<<i+1<<" "<<j+1;
                return 0;
            }
        }
        sum=0;
    }
return 0;
}
