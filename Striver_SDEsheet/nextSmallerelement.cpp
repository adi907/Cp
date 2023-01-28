// Approach: Start from end. Pop until stacks top has element smaller than current element. If stack gets empty place -1 else stack's top. Finally push the current element too in the stack
// Time complexity: O(N+N) {extra N for popping the N already pushed} ; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums, int n){
    vector<int> ans(n);
    stack<int> st;
    
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]<=st.top()){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=st.top();
        }
        st.push(nums[i]);
    }
return ans;    
}