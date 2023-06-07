// Approach: Create root node as middle element of array & call the same for root's left & right with array
// Time complexity: O(N) ; Space complexity: O(1)

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

TreeNode* helper(vector<int> nums,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=helper(nums,s,mid-1);
    root->right=helper(nums,mid+1,e);
return root;   
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums,0,nums.size()-1);
}