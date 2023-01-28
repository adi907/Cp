// Naive Approach: Use stack of type pairs(value, min value till current element)
// Time complexity: O(1) ; Space complexity: O(N+N)

#include<bits/stdc++.h>
using namespace std;

class MinStack_Naive{
    stack<pair<int,int>> st;
    public:
        MinStack_Naive(){}
    
    void push(int val){
        if(st.empty() || val<st.top().second){
            st.push({val,val});
            return;
        }
        st.push({val,st.top().second});
    }
    
    void pop(){
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin(){
        return st.top().second;
    }
};

// Optimal Approach: Use a minI variable to store min value till now. But to find previous minI's use Mathematical reln bw them: stackValue{always lesser than minInew}=2*minInew-minIold and push this in stack but keep actual value in minI. To check if an element is min,see if stack value is lesser than minI
// Time complexity: O(1) ; Space complexity: O(N)

class MinStack {
    stack<long long int> st;
    long long int minI;

    public:
    MinStack(){
        minI=INT_MAX;
    }
    
    void push(int value){
        long long int val=value;
        if(st.empty()){
            minI=val;
            st.push(val);
        }else{
            if(val<minI){
                long long int num=2*val-minI;
                st.push(num);
                minI=val;
            }else{
                st.push(val);
            }
        }
    }
    
    void pop(){
        if(st.empty()){
            return;
        }
        if(st.top()<minI){//element being popped is min Element
            minI=2*minI-st.top();
        }
        st.pop();
    }
    
    int top(){
        if(st.empty()){
            return -1;
        }
        if(st.top()<minI){
            return minI;
        }
        return st.top();
    }
    
    int getMin(){
        if(st.empty()){
            return -1;
        }
        return minI;
    }
};