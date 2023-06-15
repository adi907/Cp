// Approach: 
// Time complexity: O() ; Space complexity: O()

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

string serializeTree(TreeNode *root){
    if(root==NULL){
        return "";
    }
    queue<TreeNode*> q;
    q.push(root);

    string str="";
    while(!q.empty()){
        int n=q.size();
        int flag=0;

        for(int i=0;i<n;i++){
            TreeNode* curr=q.front();
            q.pop();

            if(curr==NULL){
                str=str+"#,";
                continue;
            }
            flag=1;
            str=str+to_string(curr->val)+",";
            q.push(curr->left);
            q.push(curr->right);
        }
    
    }
return str;
}

TreeNode* deserializeTree(string str){
    if(!str.size()){
        return NULL;
    }
    stringstream ss(str);

    string data;
    getline(ss,data,',');

    TreeNode* root=new TreeNode(stoi(data));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();

        getline(ss,data,',');

        if(data=="#"){
            curr->left=NULL;
        }else{
            TreeNode* l=new TreeNode(stoi(data));
            curr->left=l;
            q.push(l);
        }

        getline(ss,data,',');
        if(data=="#"){
            curr->right=NULL;
        }else{
            TreeNode* r=new TreeNode(stoi(data));
            curr->right=r;
            q.push(r);
        }
    }

return root;
}