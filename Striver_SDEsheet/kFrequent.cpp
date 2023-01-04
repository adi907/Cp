// Approach: Create a hashmap which stores key,frequency pairs. Then push all of these pairs into max heap & return first k elements
// Time complexity: O(kLogN) ; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        int freq;
};

struct compare{
    bool operator()(node n1,node n2){
        return n1.freq<n2.freq;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> ourMap;

    for(int i=0;i<nums.size();i++){
        ourMap[nums[i]]++;
    }        

    priority_queue<node,vector<node>,compare> pq;

    for(auto it:ourMap){
        pq.push({it.first,it.second});
    }
    vector<int> ans;

    for(int i=0;i<k;i++){
        node n=pq.top();
        pq.pop();
        ans.push_back(n.val);
    }
return ans;
}