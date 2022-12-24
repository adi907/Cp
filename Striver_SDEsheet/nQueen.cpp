// Approach: Same as NQueens before. Better isSafe() function{done via hashing}. See formulas for left and right diagnol indices
// Time comlexity: O(N!*N)  ; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;
 
bool isSafe(int i,int j,vector<string>&board,unordered_map<int,int>colMap,unordered_map<int,int>lDigMap,unordered_map<int,int>rDigMap){
    char s='Q';
    // Col check
    if(colMap[j]==1){
        return false;
    }
    
    // LDiagnol check: (n-1)+(j-i) => Gives const. value of sum for all left diagnol indices {if taking vector take of size 2n-1}
    if(lDigMap[board[0].size()-1+(j-i)]==1){
        return false;
    }
    
    // RDiagnol check: (i+j) => Gives const. value of sum for all right diagnol indices
    if(rDigMap[i+j]==1){
        return false;
    }

return true;
}


void helper(int x,vector<string>&board,vector<vector<string>>&ans,unordered_map<int,int>colMap,unordered_map<int,int>lDigMap,unordered_map<int,int>rDigMap){
    if(x>=board.size()){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<board[x].size();i++){
        if(isSafe(x,i,board,colMap,lDigMap,rDigMap)){
            board[x][i]='Q';
            colMap[i]=1;
            lDigMap[(board[0].size()-1)+(i-x)]=1;
            rDigMap[(i+x)]=1;

            helper(x+1,board,ans,colMap,lDigMap,rDigMap);

            board[x][i]='.';
            colMap[i]=0;
            lDigMap[(board[x].size()-1)+(i-x)]=0;
            rDigMap[(i+x)]=0;
        }
    }
return;
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board;
    string row="";
    for(int i=0;i<n;i++){
        row.push_back('.');
    }
    for(int i=0;i<n;i++){
        board.push_back(row);
    }
    unordered_map<int,int> colMap;
    unordered_map<int,int> lDigMap;
    unordered_map<int,int> rDigMap;
    helper(0,board,res,colMap,lDigMap,rDigMap);
    
return res;
}

int main(){
    int n;
    cin>>n;

    vector<vector<string>> ans;
    ans=solveNQueens(n);

    for(int i=0;i<ans.size();i++){
        cout<<"Sol "<<i+1<<":"<<endl;
        for(int j=0;j<ans[i].size();j++){
            for(int k=0;k<ans[i][j].size();k++){
                cout<<ans[i][j][k]<<" ";
            }cout<<endl;
        }cout<<"\n\n";
    }

}