// Naive Approach: Store inorder traversal of bst(which is sorted). Do 2pointer to find target sum
// Time complexity: O(N+N) ; Space complexity: O(N)

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

void helper(vector<int>& nums,TreeNode* root){
    if(root==NULL){
        return;
    }

    helper(nums,root->left);
    nums.push_back(root->val);
    helper(nums,root->right);
}
bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    helper(nums,root);

    int i=0;
    int j=nums.size()-1;

    while(i<j){
        if(nums[i]+nums[j]==k){
            return true;
        }else if(nums[i]+nums[j]<k){
            i++;
        }else{
            j--;
        }
    }

return false;
}

// Optimal Approach: Use 2 BST iterators, 1 normal & other which does just the opposite(reverse inorder->descending order). Instead of creating 2 different clases for normal & opposite, use flag in same class to define flow of elements into stack.Now use 2 pointer to find key sum
// Time complexity: O(N) {next() + before() called max total N times} ; Space complexity: O(H)*2

class BSTIterator {
    private:
        stack<TreeNode*> st;
        bool reverse;

        void pushAll(TreeNode* root){
            if(reverse){
                while(root!=NULL){
                    st.push(root);
                    root=root->right;
                }
            }else{
                while(root!=NULL){
                    st.push(root);
                    root=root->left;
                }
            }
        }

    public:
        BSTIterator(TreeNode* root, bool isReverse) {
            // reverse=true -> before
            // reverse=false -> next
            reverse=isReverse;
            pushAll(root);
        }

        int next(){
            TreeNode* curr=st.top();
            st.pop();
            if(reverse){
                pushAll(curr->left);
            }else{
                pushAll(curr->right);
            }

        return curr->val;
        }

        bool hasNext() {
            return !st.empty();
        }
};

bool findTarget_optimal(TreeNode* root, int k) {
    if(root==NULL){
        return false;
    }

    BSTIterator fwd(root,false);
    BSTIterator rev(root,true);

    int i=fwd.next();
    int j=rev.next();

    while(i<j){
        if(i+j==k){
            return true;
        }else if(i+j<k){
            i=fwd.next();
        }else{
            j=rev.next();
        }
    }
return false;
}
