// Approach: Do a level order traversal while keeping track of going to left and right levels as -1 & +1(root's level=0). Keep a ordered map & keep updating new entries of a particular level. Finally iterate this map & store values corres. to each level(in ordered way via ordered map)
// Time complexity: O(N) ; Space complexity: O(2N)

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

vector<int> bottomView(TreeNode *root) {
    queue<pair<TreeNode*,int>> q;
    map<int,int> mp;

    q.push({root,0});

    while(!q.empty()){
        TreeNode* curr=q.front().first;
        int lvl=q.front().second;
        q.pop();

        if(curr->left!=NULL){
            q.push({curr->left,lvl-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,lvl+1});
        }
        mp[lvl]=curr->data;
    }
    vector<int> ans;
    for(auto it:mp){
        ans.push_back(it.second);
    }

return ans;
}