// Approach: Iterate until find empty element. Then see which element sage to set there and send box for further recursion. If gives ans. then good otherwise remove element back to empty element
// Time complexity: O(9^(n^2)) {For each cell (n^2 board) we have 9 options =>Worst case}  ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,vector<vector<char>>board,char key){
    int x=(i/3)*3;
    int y=(j/3)*3;

    for(int a=0;a<9;a++){
        //row check
        if(board[i][a]==key){
            return false;
        }
        //col check
        if(board[a][j]==key){
            return false;
        }
        //box check
        if(board[x+(a/3)][y+(a%3)]==key){
            return false;
        }
    }
return true;
}
bool helper(vector<vector<char>>&board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isSafe(i,j,board,c)){
                        board[i][j]=c;
                        if(helper(board)){
                            return true;
                        }
                        board[i][j]='.';
                    }
                }
            return false;
            }
        }
    }
return true;
}
void solveSudoku(vector<vector<char>>& board) {
    helper(board);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<char>> board;
    vector<char>row;

    char c;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>c;
            row.push_back(c);
        }
        board.push_back(row);
        row.erase(row.begin(),row.end());
    }

    solveSudoku(board);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}