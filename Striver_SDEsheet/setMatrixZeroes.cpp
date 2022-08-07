// BRUTE FORCE: Time complexity(O(n*m+n+m)); Space complexity(O(n*m))
// Make duplicate of matrix; iterate over original, send coordinates of 0's to duplicate to set zeroes, finally make the duplicate the orignal
#include <bits/stdc++.h> 
using namespace std;

void setZero_helper(vector<vector<int>> &duplicate,int x,int y){
    int rows=duplicate.size();
    int cols=duplicate[0].size();
    
    for(int i=0;i<rows;i++){
        duplicate[i][y]=0;
    }
    
    for(int j=0;j<cols;j++){
        duplicate[x][j]=0;
    }
}

void setZeros(vector<vector<int>> &matrix){
    // Write your code here.
    int rows=matrix.size();
    int cols=matrix[0].size();
    
    vector<vector<int>> duplicate;
    duplicate=matrix;
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                setZero_helper(duplicate,i,j);
            }
        }
    }
    
    matrix=duplicate;
}

// Optimised approach: Time complexity(O(n*m+n*m)); Space complexity(O(1))
// Iterate over the 2d vector. Whenver encounter a 0; set its row-parent and col-parent to 0 an if 0 is in parent row(row0) or parent col(col0) then set bool row or col to true; then again iterate the 2d vector but this time leave the row0 & col0 elements. If any of their row-parent||col-parent==0 then set the element to 0. Then finally check the bool row,col if they're true/false; If true then set the whole parent row/col to 0
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix){
    bool row=false;
    bool col=false;
    
    int rows=matrix.size();
    int cols=matrix[0].size();
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                if(i==0){
                    row=true;
                }
                if(j==0){
                    col=true;
                }
                matrix[0][j]=0;
                matrix[i][0]=0;
                
            }
        }
    }
    
    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++){
            if(matrix[0][j]==0||matrix[i][0]==0){
                matrix[i][j]=0;
            }
        }
    }
    
    if(row){
        for(int j=0;j<cols;j++){
            matrix[0][j]=0;
        }
    }
    if(col){
        for(int i=0;i<rows;i++){
            matrix[i][0]=0;
        }
    }
}