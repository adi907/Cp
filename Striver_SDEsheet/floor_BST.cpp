// Approach: Just like finding predecessor but this time also take care if node's value=target value
// Time complexity: O(H) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int floorInBST(TreeNode* root, int X){
    int ans=-1;
    while(root!=NULL){
        if(root->val==X){
            return X;
        }

        if(root->val<X){
            ans=root->val;
            root=root->right;
        }else{
            root=root->left;
        }
    }
return ans;
}