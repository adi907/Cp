// Naive approach: Make a new LL. Iterate over both LL, keep storing smaller of both lists. At end check which has not reached its end. Insert all of that LL remaining elements
// Time complexity: O(M+N); Space complexity: O(M+N){to store sorted elements in a new ll}

// Faster than optimised but more space
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){
    if(first==NULL && second==NULL){
        return NULL;
    }
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    
    Node<int>* start1=first;
    Node<int>* start2=second;
    
    Node<int>* head;
    
    if(start1->data<start2->data){
        head=start1;
        start1=start1->next;
    }else{
        head=start2;
        start2=start2->next;
    }
    
    Node<int>* head_temp=head;
    
    while(start1!=NULL && start2!=NULL){
        if(start1->data<start2->data){
            head_temp->next=start1;
            start1=start1->next;
            
            head_temp=head_temp->next;
        }else{
            head_temp->next=start2;
            start2=start2->next;
            
            head_temp=head_temp->next;
        }
    }
    
    while(start1!=NULL){
        head_temp->next=start1;
        start1=start1->next;
        head_temp=head_temp->next;
    }
    while(start2!=NULL){
        head_temp->next=start2;
        start2=start2->next;
        head_temp=head_temp->next;
    }
    
    head_temp->next=NULL;
    
return head;
}

// Optimised approach: In the LL with smaller head, intitialize left and right(just next to left)(Keep a prev also) & curr in other LL. Now check if curr lies in range of left & right.If true place curr next to prev update prev. Otherwise update right and prev. At end check if any curr elements left and put them all in LL
// Time complexity: O(M+N); Space complexity: O(1)

// Slower than naive but no extra space


Node<int>* mergeTwoLists(Node<int>* list1, Node<int>* list2) {
    if(!list1 && !list2){
        return NULL;
    }
    if(!list1){
        return list2;
    }
    if(!list2){
        return list1;
    }
    Node<int>* left;
    Node<int>* right;
    Node<int>* prev;

    Node<int>* curr;
    Node<int>* temp;
    
    if((list1->data)<(list2->data)){
        left=list1;
        right=left->next;
        curr=list2;
        prev=left;
    }else{
        left=list2;
        right=left->next;
        curr=list1;
        prev=left;
    }
    
    while(right!=NULL && curr!=NULL){
        if(curr->data>=left->data && curr->data<=right->data){
            temp=curr;
            curr=curr->next;
            prev->next=temp;
            temp->next=right;
            
            prev=prev->next;
        }else{
            right=right->next;
            prev=prev->next;
        }
    }
    
    
    while(curr!=NULL){
        temp=curr;
        curr=curr->next;
        prev->next=temp;
        temp->next=right;
        
        prev=prev->next;   
    }
return left;
}
