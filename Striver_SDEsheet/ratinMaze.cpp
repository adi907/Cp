// This generates all possible solutions(unlike prev.code in cpp folder)

// Approach: Just like before but this time keep conversion of 1d to 2d indexing(store all solutions in a 2d vector with each 1d vector containing a matrix)
// Time complexity: O(4^(m*n)) {m = max.depth of recursion tree} ; Space complexity: O(m*n)

#include<bits/stdc++.h>
using namespace std;

void helper(int i,int j,int n,vector<vector<int>>maze,vector<int>path,vector<vector<int>>&sol){
    int ind=(i*n)+j;
    if(i==n-1 && j==n-1){
        path[ind]=1;
        sol.push_back(path);
        return;
    }
    
    vector<int>di={1,0,-1,0};
    vector<int>dj={0,1,0,-1};

    for(int x=0;x<4;x++){
        int a=i+di[x];
        int b=j+dj[x];
        int nextind=(a*n)+b;
        if(a>=0 && b>=0 && a<n && b<n && maze[a][b]==1 && path[nextind]==0){
            path[ind]=1;
            helper(a,b,n,maze,path,sol);
            path[ind]=0;
        }
    }
        

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> sol;
    vector<int>path;
    path.resize(n*n,0);
    
    helper(0,0,n,maze,path,sol);
    
return sol;    
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,ele;
    cin>>n;

    vector<vector<int>>maze;
    vector<int>row;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ele;
            row.push_back(ele);
        }
        maze.push_back(row);
        row.erase(row.begin(),row.end());
    }

    vector<vector<int>> path;
    path=ratInAMaze(maze,n);

    for(int i=0;i<path.size();i++){
        for(int j=0;j<path[i].size();j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }

}


/*

void helper(int ind,int n,vector<vector<int>>maze,vector<int>path,vector<vector<int>>&sol){
    int i=ind/n;
    int j=ind%n;
    if(i==maze.size()-1 && j==maze[0].size()-1){
        path[ind]=1;
        sol.push_back(path);
        return;
    }
    
    if(i>=n || j>=n || maze[i][j]==0){
        return;
    }
    path[ind]=1;
    helper(ind+1,n,maze,path,sol);
    
    helper(ind+n,n,maze,path,sol);
    path[ind]=0;    

}
*/

