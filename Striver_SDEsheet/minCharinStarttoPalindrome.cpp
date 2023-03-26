// Naive Approach(2 pointer approach): Start checking the string each time if it is a palindrome and if not, then delete the last character and check again. When the string gets reduced to either a palindrome or an empty string then the number of characters deleted from the end till now will be the answer as those characters could have been inserted at the beginning of the original string in the order which will make the string a palindrome
// Time complexity: O(N*N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int minCharsforPalindrome_Naive(string str) {
	int i=0;
    int j=str.size()-1;
    int ans=0;
    int trimmed=j;

    while(i<j){
        if(str[i]==str[j]){
            i++;j--;
        }else{
            ans++;
            i=0;
            j=--trimmed;
        }
    }

return ans;
}


// Optimal Approach(Using kmp algo): Compute lps array of a newstring i.e(string+"special char like $"+reverse_string). Return str.size()-last value of lps (see logic in notebook)
// Time complexity: O(N) ; Space complexity: O(N)

vector<int> computeLPS(string s){
    vector<int> lps(s.size());
    lps[0]=0;

    int len=0;
    for(int i=1;i<s.size();i++){
        if(s[len]==s[i]){
            len++;
            lps[i]=len;
        }else{
            while(len>0){
                len=lps[len-1];
                if(s[len]==s[i]){
                    len++;
                    lps[i]=len;
                    break;
                }
            }
            if(len==0){
                lps[i]=0;
            }
        }
    }

return lps;
}

int minCharsforPalindrome(string str) {
    string rev=str;
    reverse(rev.begin(),rev.end());

    string newstr=str+ "$" + rev;

    vector<int> lps=computeLPS(newstr);

return str.size()-lps.back();
}
