// Naive approach: Iterate LL, keep creating nodes and store these new nodes along with original LL nodes in a hashmap. Now iterate LL again. This time search the next & random ptr. of that node corresponding to the new LL and make connections. Keep iterating until original LL reaches NULL
// Time complexity:O(N+N) ; Space complexity:O(N) {for hashmap; not for answer LL}

#include<bits/stdc++.h>
using namespace std;

template <typename T>   
class LinkedListNode{
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data){
            this->data = data;
            this->next = NULL;
        }
};


LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head){
    unordered_map<LinkedListNode<int>*,LinkedListNode<int>*> ourMap;
    
    LinkedListNode<int>* start=head;
    
    while(start!=NULL){
        LinkedListNode<int>* dummy=new LinkedListNode<int>(start->data);
        ourMap[start]=dummy;
        
        start=start->next;
    }
    start=head;
    
    while(start!=NULL){
        (ourMap[start])->next=ourMap[start->next];
        (ourMap[start])->random=ourMap[start->random];
        start=start->next;
    }
return ourMap[head];  
}

// Optimal approach: Put the duplicate nodes in bw of original nodes. Now traverse this LL and point random pointer of these duplicate to next of what original nodes random pointer points to(keep check if any's random points to null). Then finally get both LL to original state connecting next's of new LL nodes and reconnecting next's of original LL
// Time complexity:O(N+N+N) ; Space complexity:O(1)

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    Node* start=head;
    
    while(start!=NULL){
        Node* dummy=new Node(start->val);
        dummy->next=start->next;
        start->next=dummy;
        start=start->next->next;
    }
    
    start=head;
    
    while(start!=NULL && start->next!=NULL){
        (start->next)->random=(start->random);
        if(start->random!=NULL){
            start->next->random=start->random->next;
        }else{
            start->next->random=NULL;
        }
        start=start->next->next;
    }
    
    start=head;
    Node* dummy1=new Node(0);
    Node* newhead=dummy1;
    
    while(start!=NULL){
        dummy1->next=start->next;
        start->next=start->next->next;
        start=start->next;
        dummy1=dummy1->next;
        dummy1->next=NULL;
    }
return newhead->next;
}