// Approach: Check for each color if valid(i.e no neighbouring should have had same color). If valid then assign color and send for further checking. If correct return true otherwise remove that color back to default. If no color able to satisfy return false
// Time complexity: O(N^M )   ; Space complexity: O(N)

#include <bits/stdc++.h> 
using namespace std;

bool isValid(vector<vector<int>> mat,vector<int> color,int node,int ch){
    for(int i=0;i<mat[node].size();i++){
        if(mat[node][i]==1 && color[i]==ch){
            return false;
        }
    }
return true;
}

bool helper(vector<vector<int>>mat,int m,int node,vector<int>& color){
    if(node==mat.size()){
        return true;
    } 
        
    for(int j=1;j<=m;j++){
        if(isValid(mat,color,node,j)){
            color[node]=j;
            if(helper(mat,m,node+1,color)){
                return true;
            }
            color[node]=-1; 
        }
    }
return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    vector<int> color;
    color.resize(mat.size(),-1);
    if(helper(mat,m,0,color)){
        return "YES";
    }else{
        return "NO";
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;

while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat;
    vector<int> row;

    int ele;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ele;
            row.push_back(ele);
        }
        mat.push_back(row);
        row.erase(row.begin(),row.end());
    }

    string ans="";
    ans=graphColoring(mat,m);

    cout<<ans<<endl;
}
}