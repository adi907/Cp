// Approach: Find nse & pse of each element. Using this we calculate max window sizes for each element can remain min. Now see for each window size, max value. If no one claims a window size, max is the next bigger window size element than it{see an edge case in code}
// Time complexity: O(7N) ; Space complexity: O(4N)

#include<bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> nums, int n) {
    vector<int> nse;nse.resize(n,-1);
    vector<int> pse;pse.resize(n,-1);
    vector<int> len;len.resize(n,-1);

    stack<int> st;

    //calculate nse
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i]=n;
        }else{
            nse[i]=st.top();
        }
        st.push(i);
    }

    while(!st.empty())st.pop();

    //calculate pse
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i]=-1;
        }else{
            pse[i]=st.top();
        }
        st.push(i);
    }

    for(int i=0;i<n;i++){
        len[i]=(nse[i]-1)-(pse[i]+1)+1;
    }
    vector<int> ans;ans.resize(n,INT_MIN);

    for(int i=0;i<n;i++){
        ans[len[i]-1]=max(nums[i],ans[len[i]-1]);
    }

    int lastKey=ans[n-1];
    for(int i=n-1;i>=0;i--){
        if(ans[i]==INT_MIN){
            ans[i]=lastKey;
        }else{
            ans[i]=max(lastKey,ans[i]); //there is a chance that the max element of a bigger window size might be also max for the next smaller window size
            lastKey=ans[i];
        }
    }
return ans;
}