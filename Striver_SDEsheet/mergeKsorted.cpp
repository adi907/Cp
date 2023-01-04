// Approach: Create a min Heap which at a time stores 1 element of each array. First push starting elements of all and then keep popping the top and pushing next element of the array where this element was taken from
// Time complexity: O(NlogK) ; Space complexity: O(K)
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    int parent;
    int index;
};

struct compare{
  bool operator()(node n1,node n2){
        return n1.val>n2.val;
  }  
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    priority_queue<node,vector<node>,compare> pq;
    vector<int>ans;

    for(int i=0;i<k;i++){
        pq.push({kArrays[i][0],i,0}); 
    }

    while(!pq.empty()){
        node n=pq.top();
        pq.pop();

        int index=n.index;
        int val=n.val;
        int parent=n.parent;

        ans.push_back(val);
        index++;
        if(index<kArrays[parent].size()){
            pq.push({kArrays[parent][index],parent,index});
        }
    }

return ans;
}