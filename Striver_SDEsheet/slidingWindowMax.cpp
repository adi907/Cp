// Naive Approach: Iterate through k elements,(n-k)times and find max of them each time
// Time complexity: O((N-k)*k) ; Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow_Naive(vector<int>& nums, int k){
    vector<int> ans;
    for(int i=0;i<=nums.size()-k;i++){
        int maxI=INT_MIN;
        for(int j=i;j<=i+k-1;j++){
            maxI=max(maxI,nums[j]);
        }
        ans.push_back(maxI);
    }
return ans;
}

// Approach: Use a DEque. Store elements in it in a decreasing order(pop & push acc. to that){start pushing front of this queue into ans after i>=k-1}. Keep check of removing elements outside window size
// Time complexity: O(N+N) ; Space complexity: O(N)

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        while(!dq.empty() && (nums[i]>nums[dq.back()])){
            dq.pop_back();
        }
        if(!dq.empty() && dq.front()<i-k+1){
            dq.pop_front();
        }
        
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
return ans;
}