// Approach: Iterate the string. For each character expand outwards: in both dir. Expand from same index(for odd len pal.) & from 1 index apart(for even len pal.)
// Time complexity: O(N*N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int l,r;
        int maxLen=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            //odd length
            l=r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>maxLen){
                    maxLen=r-l+1;
                    ans=s.substr(l,maxLen);
                }
                l--;r++;
            }

            //even length
            l=i;r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>maxLen){
                    maxLen=r-l+1;
                    ans=s.substr(l,maxLen);
                }
                l--;r++;
            }

        }
return ans;
}