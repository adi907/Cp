// Approach: A query vector is given. In which if 0-> Insert the element after it ,1-> print(store in vector) and pop element
// Time complexity: O(k*logN) {k= size of query vector} ; Space complexity: O(k)

#include <bits/stdc++.h> 
using namespace std;

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>ans;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<q.size();i++){
        if(q[i][0]==0){
            pq.push(q[i][1]);
        }else{
            ans.push_back(pq.top());
            pq.pop();
        }
    }
return ans;
}
