// Approach: Swap left and right side of the root. And send recursive call to children
// Time complexity:O(N) ; Space complexity:O(H)
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

void mirror(TreeNode* root) {
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    
    if(root->left==NULL){
        root->left=root->right;
        root->right=NULL;
        mirror(root->left);
    }else if(root->right==NULL){
        root->right=root->left;
        root->left=NULL;
        mirror(root->right);
    }else{
        TreeNode* temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }
    
}