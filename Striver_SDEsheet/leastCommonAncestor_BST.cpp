// Approach: If both elements present in right or left direction go in that respective direction. When both are in different direction or the node has value equal to 1 of the search nodes, that node is the common ancestor
// Time complexity: O(H) ; Space complexity: O(1)

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

TreeNode* helper(TreeNode* root,TreeNode*p, TreeNode* q){
    if(root==NULL){
        return NULL;
    }

    if(p->val<root->val && q->val<root->val){
        return helper(root->left,p,q);
    }
    if(p->val>root->val && q->val>root->val){
        return helper(root->right,p,q);
    }

return root;// if the paths are split OR any 1 of the value is equal to root's value return Root
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return helper(root,p,q);
}

/*
Bad code
int helper(TreeNode* root,TreeNode* p,TreeNode* q,int match,TreeNode*& ans){
        if(root==NULL){
            return 0;
        }
        if((p->val>=root->val && q->val<=root->val)||(p->val<=root->val && q->val>=root->val)){
            match+=helper(root->left,p,q,match,ans)+helper(root->right,p,q,match,ans);
        }else if(p->val>=root->val && q->val>=root->val){
            match+=helper(root->right,p,q,match,ans);
        }else{
            match+=helper(root->left,p,q,match,ans);
        }

        if(match>2){
            return 3;
        }
        if(root->val==p->val||root->val==q->val){
            match++;
        }
        if(match==2){
            match=3;
            ans=root;
        }
    
    return match;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        int k=helper(root,p,q,0,ans);
    return ans;
    }
*/