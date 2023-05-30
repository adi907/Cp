// Approach: Create a threaded binary tree. Go to rightmost of left of curr node and connect it to curr. Keep doing this. Keep check if you already traversed(link already created). If so break the link and store the current value. See notebook for more
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

vector<int> MorrisinorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr;
    TreeNode* prev;
    curr=root;

    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->val);
            curr=curr->right;
        }else{
            prev=curr->left;

            //find rightmost in left subtree
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr; // came first time, make connection, move left for further connections
                curr=curr->left;
            }else{ // connection already made, break connection, print value , move right only
                prev->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
    }   
return inorder;
}