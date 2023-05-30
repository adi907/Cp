// Approach: Just like Morris Inorder just this time store the current's value first time only while link is being created. See notebook for more
// Time complexity: amortized O(N) ; Space complexity: O(1)

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


vector<int> MorrispreorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* curr;
    TreeNode* prev;
    curr=root;

    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->val);
            curr=curr->right;
        }else{
            prev=curr->left;

            //find rightmost in left subtree
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr; // came first time, make connection, print value, move left for further connections
                preorder.push_back(curr->val);
                curr=curr->left;
            }else{ // connection already made, break connection , move right only
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }   
return preorder;
}
