// Approach: Each time take a decision. Either take element or dont take.
// Time complexity: O(2^n*k) {k=avg. length}  ; Space complexity: O(2^n*k)

#include<bits/stdc++.h>
using namespace std;

void helper(int ind,int k, vector<int> arr,vector<int>sol,vector<vector<int>>&res){
    if(ind>=arr.size()){
        return;
    }
    sol.push_back(arr[ind]);
    k-=arr[ind];
    if(k==0){
        res.push_back(sol);
    }
    helper(ind+1,k,arr,sol,res);

    sol.pop_back();
    k+=arr[ind];
    helper(ind+1,k,arr,sol,res);
return;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k){
    vector<int> sol;
    vector<vector<int>> res;
    
    helper(0,k,arr,sol,res);
return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,k;
    int ele;
    vector<int>arr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cin>>k;
    vector<vector<int>> res;
    res=findSubsetsThatSumToK(arr,n,k);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";  
        }cout<<endl;
    }
    
return 0;
}

