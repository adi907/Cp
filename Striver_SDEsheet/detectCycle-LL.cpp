// Naive approach(Hashing): Store address of nodes in hashmap. Keep traversing and searching in Hashmap. If exists, cycle is there
// Time complexity: O(N); Space complexity: O(N)

// Optimal approach(Turtle & Hare method): Keep turtle and hare pointer(speed x,2x). If anyone reaches end: no cycle, otherwise if turtle and hare meet again cycle exists
// Time complexity: O(N); Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

bool detectCycle(Node *head){
    if(head==NULL){
        return false;
    }
    
    Node* turtle=head;
    Node* hare=head;
    
    while(hare!=NULL && turtle!=NULL){
        if(turtle->next==NULL){
            return false;
        }
        turtle=turtle->next;
        
        if(hare->next==NULL){
            return false;
        }
        hare=hare->next->next;
        
        if(hare==turtle){
            return true;
        }
    }
return false;
}