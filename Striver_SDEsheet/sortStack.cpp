// Approaach: Push all elements of stack into minHeap. Then push all elements of minHeap into stack{decreasing order}
// Time complexity: O(N+N)  ; Space complexity: O(N)

#include <bits/stdc++.h> 
using namespace std;

void sortStack(stack<int> &stack){
    priority_queue<int,vector<int>,greater<int>> pq;
    
    while(!stack.empty()){
        pq.push(stack.top());
        stack.pop();
    }
    while(!pq.empty()){
        stack.push(pq.top());
        pq.pop();
    }
}