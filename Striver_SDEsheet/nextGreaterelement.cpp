// Approach: Start from twice of end's modulo(as circular, needs iteration 2 times). Each time pop until stack's top is smaller & place the greater element than it in ans. If no element greater(stack gets empty) place -1. Also finally push the given element in stack
// Time complexity: O(2N + 2N) {2n for pushing twice the size of element and 2n for popping these pushed elements}; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums){
    vector<int> ans;
    stack<int> st;
    int n=nums.size();
    ans.resize(n,-1);
    for(int i=(2*n)-1;i>=0;i--){
        while(!st.empty() && nums[i%n]>=st.top()){
            st.pop();
        }
        if(st.empty()){
            ans[i%n]=-1;
        }else{
            ans[i%n]=st.top();
        }
        st.push(nums[i%n]);
    }
return ans;
}