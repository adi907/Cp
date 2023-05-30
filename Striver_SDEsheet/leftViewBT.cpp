// Approach: Traverse left first always before right. Keep count of max depth reached. If depth reached has never been reached before push it to ans and update maxdepth
// Time complexity: O(N) ; Space complexity: O(H)

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

void helper(TreeNode* root,vector<int>& ans,int lvl,int& maxlvl){
    if(root==NULL){
        return;
    }
    
    if(lvl>maxlvl){
        maxlvl=lvl;
        ans.push_back(root->data);
    }
    
    if(root->left!=NULL){
        helper(root->left,ans,lvl+1,maxlvl);
    }
    if(root->right!=NULL){
        helper(root->right,ans,lvl+1,maxlvl);
    }
}

vector<int> leftView(TreeNode *root){
    vector<int> ans;
    int maxlvl=-1;
   
    helper(root,ans,0,maxlvl);
  
return ans;
}