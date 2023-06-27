// Approach: 
// Time complexity: O(N*M) ; Space complexity: O(N*M)


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int pixel=image[sr][sc];
        if(pixel==color){
            return image;
        }

        int m=image.size();
        int n=image[0].size();

        q.push({sr,sc});

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;

            if(x+1<m && x+1>=0 && y<n && y>=0 && pixel==image[x+1][y]){
                q.push({x+1,y});
            }
            if(x-1<m && x-1>=0 && y<n && y>=0 && pixel==image[x-1][y]){
                q.push({x-1,y});
            }
            if(x<m && y+1<n && x>=0 && y+1>=0 && pixel==image[x][y+1]){
                q.push({x,y+1});
            }
            if(x<m && y-1<n && x>=0 && y-1>=0 && pixel==image[x][y-1]){
                q.push({x,y-1});
            }

            image[x][y]=color;
        }

    return image;
    }