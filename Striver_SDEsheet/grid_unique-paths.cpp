// Naive approach(Recursion): If reach end return 1,if out of bounds return 0. all paths possible= all paths possible(from 1 right)+ all paths possible(from 1 down)
// Time complexity: Exponential; Space complexity:Stack space(exponential)

// Better approach(Dyanamic programming): Convert the recursive solution into dyanamic hash table
// Time complexity: O(M*N); Space complexity:O(M*N)

#include<bits/stdc++.h>
using namespace std;

int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp){
        if(i==(n-1) && j==(m-1)){
            return 1;
        }
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        }
}
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
   
   int num=countPaths(0,0,m,n,dp);
    if(m==1&&n==1){
        return num;
    }
return dp[0][0];
}

// Optimal approach(Maths): Length of all possible paths is always m+n-2 i.e (m-1)+(n-1) i.e Right steps(n-1) & down steps(m-1). So all possible paths will be : m+n-2 C n-1 or m+n-2 C m-1{out of all paths of length m+n-2 choose ones with right/down steps=n-1/m-1}(take min(m,n) to be efficient)
// Time complexity: O(N-1 or M-1); Space complexity: O(1)

int Comb(int y,int x){
    double ans=1;
    for(double i=1;i<=x;i++){
        ans*=y--/i;
    }
return (int)(ans+0.5);
}
    
int uniquePaths(int m, int n) {
    int total=m+n-2;
    int dir=min(m,n);
    
    int ans=Comb(total,dir-1);
return ans;
}