// Approach: Insert all elements via inorder traversal in an array & then keep returning
// Time complexity: O(1) {for all functions (not O(N for next() bcz we insert total n elements & then call them n times. So many times no need to insert any element as element alreay inserted-> O(N/N)=O(1)))} ; Space complexity: O(N)

// Approach: Optimize space complexity by using stack & only store left branch elements first in stack. Then as you keep popping check if element has right element. If yes then insert it & all its left elements too in the stack
// Time complexity: O(1) {for all functions (not O(N for next() bcz we insert total n elements & then call them n times. So many times no need to insert any element as element alreay inserted-> O(N/N)=O(1)} ; Space complexity: O(H)

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

class BSTIterator {
    private:
        stack<TreeNode*> st;

        void pushAll(TreeNode* root){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
        }

    public:
        BSTIterator(TreeNode* root) {
            pushAll(root);
        }

        int next() {
            TreeNode* curr=st.top();
            st.pop();
            pushAll(curr->right);

        return curr->val;
        }

        bool hasNext() {
            return !st.empty();
        }
};