// Approach: Each time take a char of string and store it in sol and send rest of string for recursion.Then backtrack and remove that char from sol{this char should be present in string that will be used in next iteration-> i.e why we make (new string str) so that (string s) remains unaffected and can be used again and again}
// Time complexity: O(N!*N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

void helper(string s,string sol,vector<string>&res){
    if(s.size()==0){
        res.push_back(sol);
        return;
    }
    for(int i=0;i<s.size();i++){
        sol+=s[i];
        int n=s.size();
        string str=s.substr(0,i)+s.substr(i+1,n-i);
        
        helper(str,sol,res);
        
        sol.pop_back();
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    string sol="";
    
    helper(s,sol,ans);
return ans;
}
