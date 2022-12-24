// Naive Approach: Iterate over vector,choose and store 1 element & send rest of vector for recursion(dont make another vector, insted use hashing to know which elements have been used already)
// Time complexity: O(N!*N) ; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

/*
void helper(vector<int>nums,vector<int>sol,vector<int>map,vector<vector<int>>&ans){
    if(nums.size()==sol.size()){
        ans.push_back(sol);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(map[i]==0){
            sol.push_back(nums[i]);
            map[i]=1;

            helper(nums,sol,map,ans);

            map[i]=0;
            sol.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int>sol;

    vector<int> map;
    map.resize(nums.size(),0);

    helper(nums,sol,map,ans);

return ans;
}

*/

// Optimal approach: Swap all elements with the current index and send the rest of vector for recursion. At end just put the resultant swapped vector into ans vector
// Time complexity: O(N!*N)  ; Space complexity: O(1)
void helper(int ind,vector<int>nums,vector<vector<int>>&res){
    if(ind==nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        helper(ind+1,nums,res);
        swap(nums[ind],nums[i]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    helper(0,nums,ans);

return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,ele;
    vector<int>nums;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }
    vector<vector<int>> ans;
    ans=permute(nums);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
}