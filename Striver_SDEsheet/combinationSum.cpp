// Approach: Same element can be picked infinite times. So send 2 calls: 1. To pick same element again upto when target>0 2. To ignore current element and pick next
// Time complexity: O(2^t*k) {t=target;k=avg. length}  ; Space complexity: O(k*x) {x=no. of combinations}

#include<bits/stdc++.h>
using namespace std;

void helper(int ind,int k,vector<int>arr, vector<int>sol, vector<vector<int>>&res){
    if(ind>=arr.size()|| k<0){
        return;
    }
    if(k==0){
        res.push_back(sol);
        return;
    }

    sol.push_back(arr[ind]);
    k-=arr[ind];
    helper(ind,k,arr,sol,res);

    sol.pop_back();
    k+=arr[ind];
    helper(ind+1,k,arr,sol,res);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> sol;
    helper(0,target,candidates,sol,res);
return res;
}