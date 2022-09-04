// Naive approach: Store all elements of LL in array. Then traverse array from end and start to check if same elements or not
// Time complexity:O(N + N/2) ; Space complexity: O(N)


// Optimal approach: Traverse to middle of LL, then reverse all the rest of links to right end. Now traverse LL from left and right together and keep checking if same data or not
// Time complexity:O(N/2 + N/2 + N/2) ;Space complexity: O(1)
// Problem: Modifies the LL. Ans: Remodify LL by finding mid and rearranging it back to normal form

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode{
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data){
            this->data = data;
            this->next = NULL;
        }
};

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL||head->next==NULL){
        return true;
    }
    
    LinkedListNode<int>* slow=head;
    LinkedListNode<int>* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    LinkedListNode<int>* newstart=slow;
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* temp;
    
    while(newstart!=NULL){
        temp=newstart->next;
        newstart->next=prev;
        prev=newstart;
        newstart=temp;
    }

    newstart=prev;
    
    while(newstart!=NULL && head!=NULL){
        if(newstart->data!=head->data){
            return false;
        }
        newstart=newstart->next;
        head=head->next;
    }
return true;
}