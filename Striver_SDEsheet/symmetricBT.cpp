// Approach: Compare a node value with other side node and then send recursive call of (right child,left child),(left child,right child) to find symmetricity
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


bool helper(TreeNode* r1,TreeNode* r2){
    if(!r1 && !r2){
        return true;
    }
    if(!r1 || !r2){
        return false;
    }

return (r1->val==r2->val && helper(r1->right,r2->left) && helper(r1->left,r2->right));
}
bool isSymmetric(TreeNode* root) {
    if(root==NULL){
        return true;
    }
return helper(root->left,root->right);
}