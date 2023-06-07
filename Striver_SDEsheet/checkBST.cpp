// Naive Approach: Do inorder traversal of tree. If in sorted order return true. else false
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

void helper(TreeNode* root,vector<int>& nums){
    if(root==NULL){
        return;
    }
    helper(root->left,nums);
    nums.push_back(root->val);
    helper(root->right,nums);
}

bool isValidBST(TreeNode* root) {
    vector<int> nums;
    helper(root,nums);

    if(nums.size()==1){
        return true;
    }
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>=nums[i+1]){
            return false;
        }
    }
return true;
}

// Optimal approach: Keep an upper & lower limit for each node. If it crosses that return false
// Time complexity: O(N) ; Space complexity: O(1)

bool helper(TreeNode* root,int lower,int upper){
    if(root==NULL){
        return true;
    }

    if(root->val>lower && root->val<upper){
        return ( helper(root->left,lower,root->val) && helper(root->right,root->val,upper) ); 
    }
return false;
}

bool isValidBST(TreeNode* root) {
    return helper(root,INT_MIN,INT_MAX);
}

// Optimal approach 2: Do Morris Inorder traversal. No extra space required