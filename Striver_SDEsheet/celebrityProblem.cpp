// Approach: First push 0,N-1 in stack. Then store st.top in ans and keep comparing stacks tops with this whether they know each other or not and keep popping on basis of that. Finally verify the last element left in ans whether it is actually a celeb(in case there are none)
// Time complexity:O(3N)  ; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

bool knows(int a,int b){
    /* Pre-defined function stored in onlineJudge */
return true;
}

int findCelebrity(int n) {
 	stack<int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }

    int ans=-1;
    while(!st.empty()){
        ans=st.top();
        st.pop();

        while(!st.empty() && !knows(ans,st.top()) && knows(st.top(),ans)){
            st.pop();
        }
    }

    for(int i=0;i<n;i++){
        if(i==ans){
            continue;
        }
        if(!knows(i,ans)||knows(ans,i)){
            return -1;
        }
    }
return ans;
}