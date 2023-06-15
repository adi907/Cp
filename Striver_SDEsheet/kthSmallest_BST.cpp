// Naive Approach: Do inorder traversal. Store in an array. Return kth element
// Time complexity: O(N) ; Space complexity: O(N)

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
// Optimal Approach: Do Morris inorder traversal. Keep count of nodes traversed. Store kth node & return at end after traversing all {due to leetcode checking no change in tree}
// Time complexity: O(N) ; Space complexity: O(1)

int kthSmallest(TreeNode* root, int k) {
    TreeNode* curr=root;
    int ans;
    int cnt=0;

    while(curr!=NULL){
        if(curr->left==NULL){
            cnt++;
            if(cnt==k){
                ans=curr->val;
                // we dont return answer here eventhough it would be right is bcz we create threads and we are not correcting them. Due to which Leetcode gives runtime error. So eventhough if we get answer in start we still need to traverse whole tree, break all threads and then return ans
            }
            curr=curr->right;
        }else{
            TreeNode* temp=curr->left;
            while(temp->right!=NULL && temp->right!=curr){
                temp=temp->right;
            }

            if(temp->right==NULL){
                temp->right=curr;
                curr=curr->left;
            }else{
                temp->right=NULL;
                cnt++;
                if(cnt==k){
                    ans=curr->val;
                    // we dont return answer here eventhough it would be right is bcz we create threads and we are not correcting them. Due to which Leetcode gives runtime error. So eventhough if we get answer in start we still need to traverse whole tree, break all threads and then return ans
                }
                curr=curr->right;
            }
        }
    }
return ans;
}

// My code(Easier): Do inorder traversal. Keep count of nodes traversed. If that store in ans
// Time complexity: O(N); Space complexity: O(1)

void helper(TreeNode* root,int& cnt,int& ans,int k){
    if(root==NULL){
        return;
    }
    helper(root->left,cnt,ans,k);
    cnt++;
    if(cnt==k){
        ans=root->val;
    }
    helper(root->right,cnt,ans,k);
}

int kthSmallest(TreeNode *root, int k){
    int cnt=0;
    int ans=-1;
	helper(root,cnt,ans,k);
return ans;
}