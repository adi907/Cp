// Approach: Preorder's first element is root. Find this root in inorder. Create the rootnode. All values left of root are in leftTree & all at right in rightTree. Using this info. find Left side's inorder start/end,preorder start/end. Similarly do for right side. Send recursive calls to left & right side until inorder's Start< inorder's End
// Time complexity:O(NlogN) ; Space complexity:O(N)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode *helper(vector<int> preorder, vector<int> inorder, int preS, int preE, int inS, int inE){
    if (inS > inE){
        return NULL;
    }

    int rootData = preorder[preS];
    int rootIndex = -1;

    for (int i = 0; i < inorder.size(); i++){
        if (inorder[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    int LinS = inS;
    int LinE = rootIndex - 1;
    int LpreS = preS + 1;
    int LpreE = LpreS + (LinE - LinS);
    int RinS = rootIndex + 1;
    int RinE = inE;
    int RpreS = LpreE + 1;
    int RpreE = preE;

    TreeNode *root = new TreeNode(rootData);
    root->left = helper(preorder, inorder, LpreS, LpreE, LinS, LinE);
    root->right = helper(preorder, inorder, RpreS, RpreE, RinS, RinE);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
    int n = preorder.size();
    return helper(preorder, inorder, 0, n - 1, 0, n - 1);
}