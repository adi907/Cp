// Approach: Without checking just push the node in answer. See if the node leads to target node or not. If not pop the node and return.
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

bool helper(TreeNode* root,int x,vector<int>& ans){
	if(root==NULL){
		return false;
	}
    ans.push_back(root->data);
	if(root->data==x){
		return true;
	}
	if(helper(root->left,x,ans)|| helper(root->right,x,ans)){
		return true;
	}
    ans.pop_back();
	
return false;
}

vector<int> pathInATree(TreeNode *root, int x){
    vector<int> ans;
	helper(root,x,ans);
return ans;
}
