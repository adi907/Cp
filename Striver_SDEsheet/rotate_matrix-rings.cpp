#include<bits/stdc++.h>
using namespace std;

void rotateRings(vector<vector<int>> &matrix,int n,int m){

    int rowstart=0;int colstart=0;
    int rowend=n;int colend=m;

    int prev,curr;

    while(rowstart<rowend && colstart<colend){
        if(rowstart+1==rowend|| colstart+1==colend){
            break;
        }

        prev=matrix[rowstart+1][colstart];

        for(int i=colstart;i<colend;i++){
            curr=matrix[rowstart][i];
            matrix[rowstart][i]=prev;
            prev=curr;
        }
        rowstart++;

        for(int i=rowstart;i<rowend;i++){
            curr=matrix[i][colend-1];
            matrix[i][colend-1]=prev;
            prev=curr;
        }
        colend--;

        for(int i=colend-1;i>=colstart;i--){
            curr=matrix[rowend-1][i];
            matrix[rowend-1][i]=prev;
            prev=curr;
        }
        rowend--;

        for(int i=rowend-1;i>=rowstart;i--){
            curr=matrix[i][colstart];
            matrix[i][colstart]=prev;
            prev=curr;
        }
        colstart++;
    }

}

int main(){
    // vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> matrix ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> matrix ={{1,2,3,4,5},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    rotateRings(matrix,matrix.size(),matrix[0].size());

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]<10){
                cout<<matrix[i][j]<<"  ";
            }else{
                cout<<matrix[i][j]<<" ";
            }
        }cout<<endl;
    }
}