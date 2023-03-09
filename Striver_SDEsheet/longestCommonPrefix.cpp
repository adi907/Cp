// Approach: Iterate all strings. Store letter of 1st word and compare it to letter of all other strings. If all same then add to answer otherwise break and return current common ans
// Time complexity: O(M*N) {M is length of first word} ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string common="";
    char ch;
    for(int i=0;i<strs[0].size();i++){
        for(int j=0;j<strs.size();j++){
            if(j==0){
                ch=strs[j][i];
            }else{
                if(ch!=strs[j][i]){
                    return common;
                }
            }
        }
        common+=ch;
    }
return common;
}