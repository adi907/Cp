// Approach: Use BFS(queue). Push all rotten oranges in queue first. Then pop these and push all oranges it affects and increment time. Continue doing this. If finally not all oranges affected return -1
// Time complexity: O(N*N*4) ; Space complexity: O(N*N)

#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>> rotten;
    int count=0;
    int time=0;

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2){
                rotten.push({i,j});
            }
            if(grid[i][j]==1){
                count++;
            }
        }
    }

    if(!count){
        return 0;
    }

    int xi[]={1,-1,0,0};
    int yi[]={0,0,1,-1};

    while(!rotten.empty()){
        int x=rotten.size();
        time++;
        
        for(int i=0;i<x;i++){
            pair<int,int> loc;
            loc=rotten.front();

            int x=loc.first;int y=loc.second;

            for(int a=0;a<4;a++){
                int xf=x+xi[a];int yf=y+yi[a];
                if(xf>=0 && yf>=0 && xf<m && yf<n && grid[xf][yf]==1){
                    rotten.push({x+xi[a],y+yi[a]});
                    grid[x+xi[a]][y+yi[a]]=2;
                        count--;
                    if(!count){
                        return time;
                    }
                }
            }
        rotten.pop();
        }
    }   
return -1;
}