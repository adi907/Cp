// Approach: First initialise a 2d vector. Fill it with n vectors. 1st row is special case. Just fill it with 1. all other rows make 1st and last element(i)=1. For all remaining inner 
// Time complexity: O(N); Space complexity:O(N)

#include <bits/stdc++.h> 
using namespace std;

vector<vector<long long int>> printPascal(int n) {
  // Write your code here.
    vector<vector<long long int>> matrix;
    vector<long long int> vec;
    for(int i=0;i<n;i++){
        matrix.push_back(vec);
    }
  
    for(int i=0 ; i<n ; i++){
        matrix[i].resize(i+1);//no. of elements in each row=i+1
        matrix[i][0] = 1;matrix[i][i] = 1;//first and last element always 1
        
        //for inner elements
        for(int j=1 ; j<i ; j++){
            matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
        }
    }
    return matrix;
}
