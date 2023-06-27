// Approach: 
// Time complexity: O() ; Space complexity: O()

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val){
        pq.push(val);

        int n=pq.size();
        while(n!=k){
            pq.pop();
            n--;
        }

    return pq.top();
    }
};
