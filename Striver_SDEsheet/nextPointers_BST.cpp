// Approach: Connect your own left & right children. Then if you have a next present, connect your right child's next with your next's left child
// Time complexity: O(N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void helper(Node* root){
    if(root==NULL || root->left==NULL || root->right==NULL){
        return;
    }

    root->left->next=root->right; //joining left & right of own children

    if(root->next!=NULL){
        root->right->next=root->next->left; // joining right of own & left of the next's children
    }

    helper(root->left);
    helper(root->right);
}

Node* connect(Node* root) {
    helper(root);
return root;
}