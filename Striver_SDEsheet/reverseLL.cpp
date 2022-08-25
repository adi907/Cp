// Approch: Iterate the linked list from start to end. Each time store the actual next element in temp, then change the next element to the previous element(initially null). Then update previous to current. Then move current to next element(which was stored in temp). Finally return previous element(as current element will be out of bounds equal to NULL)
// Time complexity: O(N); Space complexity: O(1)

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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head){
    // Write your code here
    LinkedListNode<int>* start=head;
    LinkedListNode<int>* temp;
    LinkedListNode<int>* prev=NULL;
    
    while(start!=NULL){
        temp=start->next;
        start->next=prev;
        prev=start;
        start=temp;
    }
return prev;
}