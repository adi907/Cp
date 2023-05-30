// Approach: Keep a stack storing(node,order) pairs. When pushing node first time push it with order 0. 0:Preorder,Increment own value,push any left children.1:Inorder,increment own value,check for any right children.2:postorder,pop
// Time complexity: O(3N) ; Space complexity: O(4N)

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

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int>row;
    vector<vector<int>> ans(3,row);

    if(root==NULL){
        return ans;
    }

    stack<pair<TreeNode*,int>> st;
    st.push({root,0});

    // 0->preorder[0],increment own value,check for any left children
    // 1->inorder[1],increment own value,check for any right children
    // 2->postorder[2],pop

    while(!st.empty()){
        TreeNode* curr=st.top().first;
        int order=st.top().second;

        if(order==0){
            st.top().second++;
            ans[0].push_back(curr->data);
            if(curr->left!=NULL){
                st.push({curr->left,0});
            }
        }else if(order==1){
            st.top().second++;
            ans[1].push_back(curr->data);
            if(curr->right!=NULL){
                st.push({curr->right,0});
            }
        }else{
            st.pop();
            ans[2].push_back(curr->data);
        }
    }
return ans;
}
