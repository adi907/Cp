// Naive approach: Iterate over LL. Keep count of total no. of elements. When reach end again go to start. Now iterate for n/2 elements
// Time complexity:O(N+ N/2); Space complexity:O(1)


// Efficient method(Turtle & hare method): Hare moves 2x the speed of turtle. When hare reaches NULL we know turtle is at middle
// Time complexity:O(N); Space complexity:O(1)

#include<bits/stdc++.h>
using namespace std;

class Node { 
    public:
        int data;
        Node *next;
        Node(int data){
           this->data = data;
          this->next = NULL;
        }
};

Node *findMiddle(Node *head) {
    Node* turtle=head;
    Node* hare=head;
    
    while(hare!=NULL && hare->next!=NULL){
        turtle=turtle->next;
        hare=hare->next->next;
    }
return turtle;
}