// Approach: Each time push opening brackets into stacks. In case of closing brackets, if top=curr element, pop. else if No top exists(stack empty) OR top and curr element not match return false. Finally check that if stack is empty(i.e all brackets have been balanced)
// Time complexity: O(N) ; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string str){
    stack<int> st;
    char c;
    
    for(int i=0;i<str.size();i++){
        if(str[i]=='{' || str[i]=='(' || str[i]=='['){
            st.push(str[i]);
        }else{
            if(st.empty()){
                return false;
            }
            c=st.top();
            if((c=='{' && str[i]=='}') || (c=='(' && str[i]==')') || (c=='[' && str[i]==']')){
                st.pop();
            }else{
                return false;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
return true;
}
