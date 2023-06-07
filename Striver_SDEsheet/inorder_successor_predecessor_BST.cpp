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

// Naive Approach: Create an inorder array. Do Binary search to find element & its pred/successor
// Time complexity: O(N+logN) ; Space complexity: O(N)

// Better Approach: Using Morris inorder traversal as soon as you encounter a number bigger than key, it is the successor & prev is predecessor
// Time complexity: O(N) ; Space complexity: O(1)

void findPreSuc(TreeNode *root, TreeNode *&pre, TreeNode *&suc, int key){
    TreeNode *curr = root;
    TreeNode *prev = NULL;
    TreeNode *temp;

    while (curr != NULL){
        if (curr->left == NULL){
            if (curr->val == key){
                pre = prev;
            }
            if (curr->val > key){
                if (pre == NULL)
                {
                    pre = prev;
                }
                suc = curr;
                return;
            }

            prev = curr;
            curr = curr->right;
        }
        else{
            temp = curr->left;
            while (temp->right != NULL && temp->right != curr){
                temp = temp->right;
            }

            if (temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            }else{
                temp->right = NULL;
                if (curr->val > key){
                    if (pre == NULL)
                    {
                        pre = prev;
                    }
                    suc = curr;
                    return;
                }
                if (curr->val == key){
                    pre = prev;
                }

                prev = curr;
                curr = curr->right;
            }
        }
    }

    if (pre != NULL){
        return;
    }else{
        pre = prev;
        return;
    }
}

// Optimal Approach: Do binary search simply via the BST for predecessor & successor
// Time complexity: O(H)=O(logN) ; Space complexity: O(1)

void findPre(TreeNode* root, TreeNode*& pre, int key){
    while(root!=NULL){
        if(root->val<key){
            pre=root;
            root=root->right;
        }else{
            root=root->left;
        }
    }
}

void findSuc(TreeNode* root, TreeNode*& suc, int key){
    while(root!=NULL){
        if(root->val>key){
            suc=root;
            root=root->left;
        }else{
            root=root->right;
        }
    } 
}

void findPreSuc_Optimal(TreeNode* root, TreeNode*& pre, TreeNode*& suc, int key){
    findPre(root,pre,key);
        findSuc(root,suc,key);
        
    return;
}