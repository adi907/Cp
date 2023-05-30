// Approach: To sustain Child Sum Property. You can increase value of each node but cant decrease for any. So while traversing, while going down simply keep increasing value of its childrens to its own value(if children's value is less) so there is no risk that their sum comes lesser than the parent and you accidently reduce value of parent. If children's value is already more, then no problem as their sum will be greater than parent ensuring increment in parent's value.(No decrement) Similarly keep traversing down. While coming back up take care of increasing the parents value to the sum of its children value.(We are sure that value would be increasing as already both childrens value was equal to its value, while going further down, their value cant be decreased as they would do the same with their children- increment childrens value instead of decrementing their own)
// Time complexity: O(N) ; Space complexity: O(H)

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void changeTree(TreeNode* root) {
    if(root==NULL){
        return;
    }
    
    if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->left==NULL){
        root->right->data= max(root->data,root->right->data);
        changeTree(root->right);
        root->data=root->right->data;
    }
    if(root->right==NULL){
        root->left->data=max(root->data,root->left->data);
        changeTree(root->left);
        root->data=root->left->data;
    }
    if(root->left!=NULL && root->right!=NULL){
        root->left->data=max(root->data,root->left->data);
        root->right->data= max(root->data,root->right->data);
        changeTree(root->left);
        changeTree(root->right);
        root->data=root->left->data+root->right->data;
    }
return;
}