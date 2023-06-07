// Approach: First element is root. To differentiate b/w left & right find the index where values start getting greater than root index. Recursively call to find left & right of root along with their preorder arrays
// Time complexity: O(N) ; Space complexity: O(1)

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

TreeNode* helper(vector<int> preorder,int preS,int preE){
    if(preS>preE){
        return NULL;
    }

    int rootdata=preorder[preS];
    TreeNode* root=new TreeNode(rootdata);

    int i=preS+1;
    while(i<=preE && preorder[i]<rootdata){
        i++;
    }
    
    int LpreS=preS+1;
    int LpreE=i-1;
    int RpreS=i;
    int RpreE=preE;
    
    root->left=helper(preorder,LpreS,LpreE);
    root->right=helper(preorder,RpreS,RpreE);
return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n=preorder.size()-1;
    TreeNode* root=helper(preorder,0,n);

return root;
}