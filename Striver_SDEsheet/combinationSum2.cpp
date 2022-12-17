// Approach: Make all possible subset combinations(these will contain duplicate solutions also as 1 element can come again & again & we need 1 solution only once). Put them in a set
// Time complexity: O(2^n*k*k) {avg. length}

#include<bits/stdc++.h>
using namespace std;

void helper(int ind,int k, vector<int> arr,vector<int>sol,set<vector<int>>&res){
    if(ind>=arr.size()){
        return;
    }
    sol.push_back(arr[ind]);
    k-=arr[ind];
    if(k==0){
        res.insert(sol);
    }
    helper(ind+1,k,arr,sol,res);

    sol.pop_back();
    k+=arr[ind];
    helper(ind+1,k,arr,sol,res);
return;
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    vector<int> sol;
    set<vector<int>> res;
    vector<vector<int>> ans;

    sort(arr.begin(),arr.end());

    helper(0,target,arr,sol,res);
    
    for(auto it=res.begin();it!=res.end();it++){
        ans.push_back(*it);
    }
    
return ans;
}


// Approach: Pick Only the first occurences of each element for recursion & keep decrementing target. Stop if the (target<arr[i])
// Time complexity: O(2^n*k) {but much faster than 1st approach as most cases get pruned} ; Space complexity:O(k*x) {x=no. of combinations}

#include<bits/stdc++.h>

void helper(int ind,vector<int> arr,vector<int> sol,vector<vector<int>>&res,int target){
    if(target==0){
        res.push_back(sol);
        return;
    }
    
    for(int i=ind;i<arr.size();i++){
        if(arr[i]>target){
            break;
        }
        if(arr[i]==arr[i-1] && i>ind){ //duplicate elements in arr(not the first element as duplicate)
            continue;
        }
        
        sol.push_back(arr[i]);
        helper(i+1,arr,sol,res,target-arr[i]);
        sol.pop_back();
    }      
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	vector<int>sol;
    vector<vector<int>> res;
    
    sort(arr.begin(),arr.end());
    
    helper(0,arr,sol,res,target);

return res;
}