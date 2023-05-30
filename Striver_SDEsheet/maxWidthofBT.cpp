// Approach: Do level order traversal. Keep queue of type(Node,Val(long long int)). Maxwidth of level=Val(queue_last)-Val(queue_front). Instead of normal ordering(which can go to large no.) we order as (parent's Val-lowest Val in lvl)*2 +1(for left)/+2(for right)
// Time complexity: O(N) ; Space complexity: O(N)

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


int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL){
        return 0;
    }

    int maxwidth=1;

    queue<pair<TreeNode*,int>> q;
    pair<TreeNode*,int> p,curr;

    q.push({root,0});

    while(!q.empty()){
        int l=(q.front()).second;
        int r=(q.back()).second;

        maxwidth=max(maxwidth,r-l+1);

        int sz=q.size();
        for(int i=0;i<sz;i++){
            curr=q.front();
            q.pop();

            TreeNode* rt=curr.first;
            if(rt->left!=NULL){
                q.push({rt->left, (long long)(curr.second-l)*2+1});
            }
            if(rt->right!=NULL){
                q.push({rt->right, (long long)(curr.second-l)*2+2});
            }

        }
    }
return maxwidth;
}