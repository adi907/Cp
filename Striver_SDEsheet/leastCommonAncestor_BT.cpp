#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach: Check in the left & right nodes for matching values of p,q and maintain count of matched values. Now compare yourself with the value of p and q. If same increment count and check if this count is equal to total nodes. If yes, you are the common ancestor
// Time complexity:O(N) ; Space complexity:O(N)

int helper(TreeNode *root, TreeNode *p, TreeNode *q, int match, TreeNode *&ans){
    if (root == NULL){
        return 0;
    }
    match += helper(root->left, p, q, match, ans) + helper(root->right, p, q, match, ans);

    if (match > 2){ // for pruning of branches once we've found our answer
        return match;
    }

    if (root->val == p->val || root->val == q->val){
        match++;
    }

    if (match == 2){
        ans = root;
        match = 3; // for pruning of other branches that can be ignored
    }

return match;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    TreeNode *ans;
    int k = helper(root, p, q, 0, ans);

return ans;
}