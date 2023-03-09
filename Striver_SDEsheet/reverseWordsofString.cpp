// Naive Approach: Push all words in stack(1 by 1 store word in string; then after blank push word in stack and make string empty again). Finally pop all elements of stack with a space(take care of last element w/o blanks){& edge cases of multiple blanks too}
// Time complexity: O(N + w) {w=no. of words}; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

string reverseWords_Naive(string s) {
    string str="";
    string ans="";
    stack<string> st;

    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            // cout<<s[i]<<endl;
            str.push_back(s[i]);
        }else{
            st.push(str);
            str="";
        }
    }
    st.push(str);

    while(st.size()!=1){
        if(st.top()==""){
            st.pop();
        }else{
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
    }
    if(st.top()!=""){ //last element is word: just add it. Dont add a blank
        ans+=st.top();
        st.pop();
    }else{ // last element is blank: dont add it & also remove last blank added by above while loop
        ans.pop_back();
    }

return ans;
}

// Optimized approach: Iterate from start of original string. Keep pushing each word at start of ans each time.{take check of final word}
// Time complexity: O(N) ; Space complexity: O(1)

string reverseWords(string s) {
    string temp="";
    string ans="";

    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            temp+=s[i];
        }else{
            if(ans==""){
                ans=temp;
            }else{
                if(temp==""){
                    continue; //when there is no word; but just bcz ans isnt empty we might add a blank(not from temp but the " " we add )
                }
                ans=temp+" "+ans;
            }
            temp="";
        }
    }
    //final word check
    if(temp!=""){
        if(ans==""){
            ans=temp;
        }else{
            ans=temp+" "+ans;
        }
    }

return ans;
}