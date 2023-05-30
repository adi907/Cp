#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Naive approach: Check left and right height for each node and check if balanced
// Time complexity:O(N^2) ; Space complexity:
int height(TreeNode* root){
    if(!root){
        return 0;
    }
return 1+max(height(root->left),height(root->right));
}

bool isBalanced(TreeNode* root) {
    if(!root){
        return true;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    if((abs)(rh-lh)<2){
        return (isBalanced(root->left) && isBalanced(root->right));
    }
    return false;
}

// Optimal approach: Instead of checking each node. Find left and right height. If any of these -1(due to imbalance within them), directly return -1. Else check on itselft whether balanced and return its height(1+max(lh,rh))
// Time complexity:O(N) ; Space complexity:O(H)
int check(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int lh=check(root->left);
    if(lh==-1)return -1;
    int rh=check(root->right);
    if(rh==-1)return -1;

    if(abs(lh-rh)>1){
        return -1;
    }

return 1+max(lh,rh);
}

bool isBalanced(TreeNode* root){
    return (check(root)!=-1);
}