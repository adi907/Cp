// Approach: 
// Time complexity: O() ; Space complexity: O()

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

// Better code
void helper(TreeNode* root, TreeNode* &head,TreeNode* &prev){
    if(root==NULL){
        return;
    }

    helper(root->left,head,prev);

    if(prev==NULL){
        head=root;
    }else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;

    helper(root->right,head,prev); 
}

TreeNode* BTtoDLL(TreeNode* root) {
    TreeNode* head=NULL;
    TreeNode* prev=NULL;
    helper(root,head,prev);
return head;
}


// My code
void helper(TreeNode* root){
    if(root==NULL){
        return;
    }
    TreeNode* leftchild=root->left;
    TreeNode* rightchild=root->right;

    //rightmost of left st
    TreeNode* temp=root->left;
    while(temp!=NULL && temp->right!=NULL && temp->right!=root){
        temp=temp->right;
    }
    int flag=0;
    if(temp!=NULL && temp->right==root){
        flag=1;
    }

    if(temp!=NULL && temp->right==NULL){
        temp->right=root;
        root->left=temp;
    }
    if(leftchild!=NULL && !flag){
        helper(leftchild);
    }

    //leftmost of right st
    temp=root->right;
    while(temp!=NULL && temp->left!=NULL && temp->left!=root){
        temp=temp->left;
    }

    if(temp!=NULL && temp->left==root){
        return;
    }
    if(temp!=NULL && temp->left==NULL){
        temp->left=root;
        root->right=temp;
    }

    if(rightchild!=NULL){
        helper(rightchild);
    }
}

TreeNode* BTtoDLL(TreeNode* root) {
    helper(root);
    while(root->left!=NULL){
        root=root->left;
    }
return root;
}