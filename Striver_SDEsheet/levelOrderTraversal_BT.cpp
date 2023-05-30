// Approach: Keep a queue to store node. Each time take a node. Store its value.Pop it. Push its children to the queue
// Time complexity: O(N) ; Space complexity: O(H)

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if(root==NULL){
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int sz=q.size();
        vector<int> row;

        for(int i=0;i<sz;i++){
            TreeNode* curr=q.front();

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }

            row.push_back(curr->data);
            q.pop();
        }
        ans.push_back(row);
    }
return ans;
}