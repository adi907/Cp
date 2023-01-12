/*
    Approach: Keep rear and front for push and pop. Optimize by placing at prev. index which have been popped(circular queue) Take care of reinitialization of array when queue full{see imp. case in code which causes failure in test cases}
    Space complexity: O(N)
    Time complexity: 
        Enqueue(wo resizing) = Dequeue = Front = isEmpty =isFull : O(1) 
        Enqueue(resizing) = O(N)
*/

#include<bits/stdc++.h>
using namespace std;

class Queue {
private:
    int size;
    int capacity;
    int rearIndex;
    int frontIndex;
    int* arr;
public:
    
    Queue() {
        size=0;
        capacity=5;
        rearIndex=0;
        frontIndex=0;
        arr=new int[capacity];
    }

    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(size==capacity){
            int* newarr=new int[2*capacity];

            int j=0;
            for(int i=frontIndex;i<capacity;i++){
                newarr[j++]=arr[i];
            }
            for(int i=0;i<frontIndex;i++){
                newarr[j++]=arr[i];
            }
            delete[] arr;
            arr=newarr;

            capacity*=2;
            frontIndex=0;
            rearIndex=size;
        }
        /*my way
        
        arr[rearIndex%capacity]=data;
        rearIndex++;
        */ 

        arr[rearIndex]=data;
        rearIndex=(rearIndex+1)%capacity;  //v.v.imp as if not-> gives wrong answer ? why

        size++;
    }

    int dequeue() {
        if(isEmpty()){
            return -1;
        }
        int k=arr[frontIndex];
        frontIndex=(frontIndex+1)%capacity;
        size--;
    return k;
    }

    int front() {
        if(isEmpty()){
            return -1;
        }
        return arr[frontIndex];
    }
};