// Approach: Try making all possible partitions but each time include the check that left side of partition is always palindrome and then send the rest right side for recursion. Do until last element of string partitioned
// Time complexity: O(2^n*k*(n/2)) {k to insert into vector; n/2 to check palindrome} ; Space complexity:O(k*x)

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str,int start,int end){
    while(start<=end){
        if(str[start++]!=str[end--]){
            return false;
        }
    }
return true;
}

void helper(int ind,string str,vector<string>path,vector<vector<string>>&res){
    if(ind==str.size()){
        res.push_back(path);
        return;
    }

    for(int i=ind;i<str.size();i++){
        if(isPalindrome(str,ind,i)){
            path.push_back(str.substr(ind,i-ind+1));
            helper(i+1,str,path,res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) {
    vector<vector<string>> res;
    vector<string> path;
    
    helper(0,s,path,res);
return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string str;
    cin>>str;
    vector<vector<string>> res;
    res=partition(str);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }
}