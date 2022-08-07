#include<iostream>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif
    int m,n,key,arr[100][100];
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cin>>key;
    int r=0,c=m-1;
    int flag=0;
    while(r<m && c>=0){
        if(arr[r][c]==key){
            flag=1;
            break;
        }else if(arr[r][c]>key){
            c--;
        }else{
            r++;
        }
    }
    if(flag==1){
        cout<<"Element found";
    }else{
        cout<<"Element not found";
    }
    
return 0;
}
