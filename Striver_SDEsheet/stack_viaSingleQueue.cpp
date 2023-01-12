/* Approach(Using 2 queues): Keep 2 queues q1(main queue used for pop,front etc) q2(secondary queue). Each time push new element in q2. Then push all elements of q1 into q2. Finally swap q1 with q2.
Time complexity= push: O(N)
                 pop = front = isEmpty: O(1)
Space complexity= O(2N) {2 queues}

*/


/* Approach(Using single queue): Each time push the element into queue. Then pop & push rest of (n-1)elements from queue which were in front of this new element. So last element will be first(LIFO). All rest operations same
Time complexity= push: O(N)
                 pop = front = isEmpty: O(1)
Space complexity= O(N) {single queue}

*/

#include<bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }
    
    void push(int x){
        q.push(x);
        int size=q.size();

        for(int i=0;i<size-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop(){
        if(empty()){
            return -1;
        }
        int ans=q.front();
        q.pop();
    return ans;
    }
    
    int top(){
        if(empty()){
            return -1;
        }
        return q.front();
    }
    
    bool empty(){
        return (q.size()==0);
           
    return false;
    }
};
