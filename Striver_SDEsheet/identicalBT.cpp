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

// Approach: Check your own value with other roots val. Compare left & right children. Also take care of NULL nodes occurence
// Time complexity:O(N) ; Space complexity:O(H)

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL){
        return true;
    }
    if(p==NULL || q==NULL){
        return false;
    }
return (p->val==q->val && (isSameTree(p->left,q->left))&& (isSameTree(p->right,q->right)));
}