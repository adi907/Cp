// Brute force: make a new 2d array. put first row of original matrix as last column,then second row in second last column and so on...
// Time complexity: O(N*N); Space complexity: O(N*N)


// Optimised approach: Make transpose of matrix{swap if j<i}. Then reverse elements of each row
// Time complexity: O(N*N); Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);    
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());   
    }
}