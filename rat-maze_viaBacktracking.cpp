#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr,int x,int y,int n,int **solArr){
    if(arr[x][y]==1 && x<n && y<n){
        return true;
    }
    return false;
}

bool ratMaze(int **arr,int x,int y,int n,int **solArr){
    if((x==n-1) && (y==n-1)){
        solArr[x][y]=1;
        return 1;
    }

    if(isSafe(arr,x,y,n,solArr)){
        solArr[x][y]=1;
        if(ratMaze(arr,x+1,y,n,solArr)==1){
            return true;
        }
        if(ratMaze(arr,x,y+1,n,solArr)==1){
            return true;
        }
        solArr[x][y]=0;
        return false;
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int **arr=new int *[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int **solarr=new int *[n];
    for(int i=0;i<n;i++){
        solarr[i]=new int[n];
        for(int j=0;j<n;j++){
            solarr[i][j]=0;
        }
    }

    if(ratMaze(arr,0,0,n,solarr)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solarr[i][j]<<" ";
            }cout<<endl;
        }
    }else{
        cout<<"No path found :(";
    }

    
return 0;
}
