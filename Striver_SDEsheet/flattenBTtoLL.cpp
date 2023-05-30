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

TreeNode* previous=NULL;

// Approach-I: Traverse right then left to end. Keep a global variable previous(initially at NULL). Make root's left=NULL and right equal to previous element and keep updating previous element
// Time complexity: O(N); Space complexity:O(N)
void flatten1(TreeNode* root){
    if(root==NULL){
        return;
    }
    flatten1(root->right);
    flatten1(root->left);

    root->right=previous;
    root->left=NULL;
    previous=root;
}

// Approach-II: Use a Stack. Store right first then left(so left at top). Make the stacks top as root's right and root's left to NULL. now pop this stacks top and store its right and left
// Time complexity:O(N) ; Space complexity:O(N)
void flatten2(TreeNode* root){
    if(root==NULL){
        return;
    }
    stack<TreeNode*> st;

    if(root->right!=NULL){
        st.push(root->right);
    }
    if(root->left!=NULL){
        st.push(root->left);
    }

    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();

        root->left=NULL;
        root->right=node;

        if(node->right!=NULL){
            st.push(node->right);
        }
        if(node->left!=NULL){
            st.push(node->left);
        }
        root=root->right;
    }

}

// Approach-III:(just like Morris Traversal)Create links.If no left continue going right. Otherwise go to the rghtmost child of left & link to curr and also make curr->right=curr->left & curr->left=NULL and continue going right
// Time complexity:O(N)  ; Space complexity:O(1)
void flatten3(TreeNode* root){
    TreeNode* curr=root;

    while(curr!=NULL){
        if(curr->left==NULL){
            curr=curr->right;
        }else{
            //go to rightmost of left of node
            TreeNode* pre=curr->left;
            while(pre->right!=NULL){
                pre=pre->right;
            }
            pre->right=curr->right;

            curr->right=curr->left;
            curr->left=NULL;

            curr=curr->right;
        }
    }

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


    
return 0;
}