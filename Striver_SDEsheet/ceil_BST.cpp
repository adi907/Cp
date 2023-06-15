// Approach: Just like finding successor but this time also take care if node's value=target value
// Time complexity: O(H) ; Space complexity: O(1)

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

int findCeil(TreeNode *node, int x){
    int ans=-1;
    while(node!=NULL){
        if(node->val==x){
            return x;
        }

        if(node->val>x){
            ans=node->val;
            node=node->left;
        }else{
            node=node->right;
        }

    }
return ans;
}