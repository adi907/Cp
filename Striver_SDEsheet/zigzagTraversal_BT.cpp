// Approach: Just like level Order Traversal. Just keep a flag this time to reverse flow of inserting element from clockwise to anticlockwise
// Time complexity: O(N) ; Space complexity: O(N)

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> ans;

    if(root==NULL)return ans;

    queue<TreeNode*> q;
    bool flag=0;

    q.push(root);

    while(!q.empty()){
        int n=q.size();
        vector<int> row(n);
        
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }

            if(!flag){ //L to R
                row[i]=node->data;
            }else{ //R to L
                row[n-i-1]=node->data;
            }
        }
        ans.push_back(row);
        flag=!flag;
    }
return ans;
}
