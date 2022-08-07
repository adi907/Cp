#include<iostream>
using namespace std;
void pairsum(int arr[],int n,int key){
    int low=0,high=n-1;
    while(high>low){
        if(arr[low]+arr[high]>key){
            high--;
        }
        else if(arr[low]+arr[high]<key){
            low++;
        }
        else{
            cout<<arr[low]<<" "<<arr[high]<<endl;
            low++;
            high--;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif
    int n,arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pairsum(arr,n,10);
    
return 0;
}
