// Naive Approach: Use checkBST for every node
// Time complexity: O(N^2) ; Space complexity: O(1)


// Optimal Approach: 
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

// For max size BST

class Nodevalue{
    public:
        int minNode;
        int maxNode;
        int size;

        Nodevalue(int mn,int mx,int s){
            minNode=mn;
            maxNode=mx;
            size=s;
        }
};

Nodevalue size_helper(TreeNode* root){
    if(root==NULL){
        return Nodevalue(INT_MAX,INT_MIN,0); // sets it to value that can be defeated by any node(as min=INT_MAX & max=INT_MIN)
    }

    Nodevalue left=size_helper(root->left);
    Nodevalue right=size_helper(root->right);

    if(root->val>left.maxNode && root->val<right.minNode){ // it is BST
        return Nodevalue(min (root->val,left.minNode), max(root->val,right.maxNode), left.size+right.size+1); //eventhough there should be no need of min,max bcz left.minNode should be smallest & right.maxNode largest but still in case of NULL minNode may be INT_MAX & maxNode may be intMin. So check it by min & max
    }

    return Nodevalue(INT_MIN,INT_MAX,max(left.size,right.size)); // sets it to non-defeatable value(as min=INT_MIN & max=INT_MAX)
}

int maxSizeBST(TreeNode* root) {
    return size_helper(root).size;
}

// For Max Sum BST

class Nodevalue2{
    public:
        int minNode;
        int maxNode;
        int sum;

        Nodevalue2(int m,int x,int s){
            minNode=m;
            maxNode=x;
            sum=s;
        }
};

Nodevalue2 sum_helper(TreeNode* root,int& ans){
    if(root==NULL){
        return Nodevalue2(INT_MAX,INT_MIN,0); // sets it to value that can be defeated by any node(as min=INT_MAX & max=INT_MIN)
    }

    Nodevalue2 left=sum_helper(root->left,ans);
    Nodevalue2 right=sum_helper(root->right,ans);

    if(root->val>left.maxNode && root->val<right.minNode){ // it is BST
        ans=max(ans,left.sum+right.sum+root->val);
        return Nodevalue2(min (root->val,left.minNode), max(root->val,right.maxNode),left.sum+right.sum+root->val ); //eventhough there should be no need of min,max bcz left.minNode should be smallest & right.maxNode largest but still in case of NULL minNode may be INT_MAX & maxNode may be intMin. So check it by min & max
    }

    // Not a BST
    ans=max(ans,max(left.sum,right.sum));
return Nodevalue2(INT_MIN,INT_MAX,max(left.sum,right.sum)); // sets it to non-defeatable value(as min=INT_MIN & max=INT_MAX)
}

int maxSumBST(TreeNode* root) {
    int ans=0;
    Nodevalue2 k=sum_helper(root,ans);
    
return ans;
}