#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Naive Approach: Diameter of binary Tree can be either be (leftHeight+Rightheight) or it can be another path passing in the left or right node of root
// Time complexity:O(N^2) ; Space complexity:O(N)

int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int norm = height(root->left) + height(root->right);
    int diff1 = diameterOfBinaryTree(root->left);
    int diff2 = diameterOfBinaryTree(root->right);
    int ans = max(diff2, max(norm, diff1));

    return ans;
}

// Optimal Approach: Better than previous bcz here instead of calling height() for each node we call height for just 1 node and all others height calculated via it. Diameter also gets updated in the process
// Time complexity:O(N) ; Space complexity: O(N)

int height(TreeNode *root, int &diameter){
    if (root == NULL){
        return 0;
    }

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    int k = height(root, diameter);
    return diameter;
}