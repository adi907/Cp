// Approach: Just like bottom view, this time just dont update map for new entries. If entry for a level already present then ignore. Otherwise make entry in map. Finally iterate the map and store in vector in ordered way
// Time complexity: O(N) ; Space complexity: O(2N)

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};


vector<int> topView(TreeNode *root){
    queue<pair<TreeNode*,int>>q;
    map<int,int> mp;
    vector<int> ans;
    
    q.push({root,0});

    while(!q.empty()){
        TreeNode* curr=q.front().first;
        int lvl=q.front().second;

        q.pop();
        
        if(mp.count(lvl)==0){
            mp[lvl]=curr->data;
        }
        
        if(curr->left!=NULL){
            q.push({curr->left,lvl-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,lvl+1});
        }
    }
    
    for(auto it:mp){
        ans.push_back(it.second);
    }
return ans;
}