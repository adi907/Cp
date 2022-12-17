// Approach: Generate all possible subsets. Then put all of them in a set(sorted) to discard duplicates
// Time complexity:O( (2^n *(k log (x))) * 2^n)  ; Space complexity: O(2^n * k)

#include <bits/stdc++.h> 
using namespace std;

void helper(set<vector<int>>&res,vector<int>& arr,vector<int> sol,int i){
    if(i==arr.size()-1){
        sort(sol.begin(),sol.end());
        res.insert(sol);
        
        sol.push_back(arr[i]);
        sort(sol.begin(),sol.end());
        res.insert(sol);
        return;
    }
    helper(res,arr,sol,i+1);
    sol.push_back(arr[i]);
    helper(res,arr,sol,i+1);
return;
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    set<vector<int>> res;
    vector<int> sol;
    helper(res,arr,sol,0);
    
    vector<vector<int>> vec;
    
    for(auto it=res.begin();it!=res.end();it++){
        vec.push_back(*it);
    }
    
return vec;
}

// Optimal Approach: Make recursive calls based on just simply calling next index & calling the next unique elements index
// Time complexity:O(2^n*n) ;Space complexity:O(2^n*k){k= avg. length of subset}

void helper(int ind, vector<int>& arr, vector<int>&sol, vector<vector<int>> &res){
    res.push_back(sol);
    for(int i = ind; i<arr.size(); i++) {
        if(i==ind || arr[i] != arr[i-1]){
            sol.push_back(arr[i]);
            helper(i+1,arr,sol,res);
            sol.pop_back();
        }
    }
}

/*
understand: 1. Why sent by reference(see prev. recursion ques.)
Ans: No need to send all by reference. Can only just send res by referenceas we're not returning it but accessing through a 
different fn and thus changes need to be reflected globally

2. Why pop_back()
Ans: Bcz firstly we just add all elements(i==ind). Then as we backtrack, we remove the last elements & send for recursion
the new ones.{See recursion tree in n.b, the first level has element 1's recursion. Then 1 removed. Then 2 added and 2's recursion}
*/ 



vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    vector<vector<int>>res;
    vector<int>sol;
    sort(arr.begin(),arr.end());
    helper(0,arr,sol,res);
return res;
}