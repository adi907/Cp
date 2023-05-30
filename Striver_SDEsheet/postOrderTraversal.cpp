// Approach: Left Right Node
// Time complexity: O(N) ; Space complexity: O(N)

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

void helper(TreeNode* root, vector<int>& ans){
    if(root==NULL){
        return;
    }

    helper(root->left,ans);
    helper(root->right,ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    helper(root,ans);
return ans;
}