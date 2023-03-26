// Approach: For 2 words to be anagram, they must have same size & some no. of occurences of alphabets. Check size of both, then create hashmap for both's frequencies. If same then valid anagram
// Time complexity: O(N) ; Space complexity: O(2N)

#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size()!=t.size()){
        return false;
    }

    vector<int> stan;
    vector<int> curr;

    stan.resize(26,0);
    curr.resize(26,0);

    for(int i=0;i<s.size();i++){
        stan[s[i]-'a']++;
        curr[t[i]-'a']++;
    }

    if(stan==curr){
        return true;
    }
return false;
}