/* Approach(Using 2 stacks): Keep 2 stacks s1(main stack used for pop,front etc) s2(secondary stack). When pushing an element first push all elements of s1 to s2. Then add element to s1. Finally push all elements of s2 back to s1
Time complexity= push: O(2N)
                 pop = front = isEmpty: O(1)
Space complexity= O(2N) {2 stacks}

*/

/* Approach(Using 2 stacks): Keep 2 stacks: input & output. Each time push new element into input. In case of pop/front move all input elements into output. And keep popping until output not empty. If more pops after that check if any elements left in input and if not return -1  
Time complexity= push = isEmpty: O(1)
                 pop = front: O(1 amortized) {amortized = in most cases}
Space complexity= O(2N) {2 queues}
*/
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(empty()){
            return -1;
        }

        if(output.empty() && !input.empty()){ //if output gets empty and input gets elements again(in case after last pop(), push() operations were performed elements will be pushed into input)
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }

        int ans=output.top();
        output.pop();
    return ans;
    }
    
    int peek() {
        if(empty()){
            return -1;
        }

        if(output.empty() && !input.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
    return output.top();
    }
    
    bool empty() {
        return(input.size()==0 && output.size()==0);
    }
};