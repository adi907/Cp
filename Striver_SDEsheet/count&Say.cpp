// Approach: Each time send current string to helper fn where calculate freq. of all consec. same digits and store in ans & return. Then use this string for next iteration
// Time complexity: O(N*N) ; Space complexity: O(1) {only space used is to store ans}

#include<bits/stdc++.h>
using namespace std;

string helper(string str){
    string ans;
    int i=0;
    while(i<str.size()){
        char ch=str[i];
        int count=1;
        while(i+1<str.size() && str[i]==str[i+1]){
            count++;
            i++;
        }
        ans+=to_string(count) +ch;
        i++;
    }
return ans;
}

string countAndSay(int n) {
   if(n==1){
        return "1";
    }
    string str="1";
    for(int i=1;i<n;i++){
        str=helper(str);
    }
return str; 
}