// Naive Approach: Do inorder traversal, store in array. Return (n-k)th element
// Time complexity: O(N) ; Space complexity: O(N)

// Optimal Approach: Do a special Morris traversal(Right-root-Left){reverse inorder} which gives descending order. Keep count of nodes traversed. Store kth element & return at end after traversing all{due to leetcode checking no change in tree}
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

int kthLargest(TreeNode *root, int K){
    TreeNode* curr=root;
    int ans;
    int cnt=0;
    
    while(curr!=NULL){
        if(curr->right==NULL){
            cnt++;
            if(cnt==K){
                ans=curr->val;
            }
            curr=curr->left;
        }else{
            TreeNode* temp=curr->right;
            while(temp->left!=NULL && temp->left!=curr){
                temp=temp->left;
            }
            if(temp->left==NULL){
                temp->left=curr;
                curr=curr->right;
            }else{
                cnt++;
                if(cnt==K){
                    ans=curr->val;
                }
                temp->left=NULL;
                curr=curr->left;
            } 
        }
    }
return ans;
}