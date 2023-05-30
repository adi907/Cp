// Approach: Postorder's last value is root. Find this in inorder. Create the rootnode. All values left of root are in leftTree & all at right in rightTree. Using this info. find Left side's inorder start/end,postorder start/end. Similarly do for right side. Send recursive calls to left & right side until inorder's Start< inorder's End
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


TreeNode *helper(vector<int> inorder, vector<int> postorder, int inS, int inE, int poS, int poE){
    if (inS > inE){
        return NULL;
    }

    int rootData = postorder[poE];
    int rootIndex = -1;

    for (int i = inS; i <= inE; i++){
        if (inorder[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    int LinS = inS;
    int LinE = rootIndex - 1;
    int LpoS = poS;
    int LpoE = LpoS + (LinE - LinS);
    int RinS = rootIndex + 1;
    int RinE = inE;
    int RpoS = LpoE + 1;
    int RpoE = poE - 1;

    TreeNode *root = new TreeNode(rootData);
    root->left = helper(inorder, postorder, LinS, LinE, LpoS, LpoE);
    root->right = helper(inorder, postorder, RinS, RinE, RpoS, RpoE);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
    int n = inorder.size();
    return helper(inorder, postorder, 0, n - 1, 0, n - 1);
}