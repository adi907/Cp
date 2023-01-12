/*
    Approach: Just initialize array,size(for curr_size,capacity) and implement stack properties
    Space complexity: O(N)
    Time complexity: 
        Push = Pop =Top = isEmpty =isFull : O(1) 
*/

#include<bits/stdc++.h>
using namespace std;

class Stack {
    int* arr;
    int size;
    int cap;
    
    public:
    
    Stack(int capacity) {
        arr=new int[capacity];
        size=0;
        cap=capacity;
    }

    void push(int num) {
        if(this->isFull()){
            return;
        }
        arr[size++]=num;
    }

    int pop() {
        if(this->isEmpty()){
            return -1;
        } 
    return arr[--size];
    }
    
    int top() {
        if(this->isEmpty()){
            return -1;
        }
        return arr[size-1];
    }
    
    int isEmpty() {
        if(size==0){
            return 1;
        }
    return 0;
    }
    
    int isFull() {
        if(size==cap){
            return 1;
        }
    return 0;    
    }
};