// Naive approach: Count total no. of nodes. Then iterate (n-k)nodes and Delete(Make connection with next to next)
// Time complexity: O(N+N); Space complexity: O(1)


// Optimal approach(Hare & turtle method): Give the hare a headstart of k elements. Then iterate hare & turtle together. When hare is at last element stop as turtle is at kth element from end. Then delete (Make connection with next to next)
// Time complexity: O(N); Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start=new ListNode();
    start->next=head;
    
    ListNode* hare=start;
    ListNode* turtle=start;
    
    if(head==NULL){
        return NULL;
    }
    
    for(int i=0;i<n;i++){
        hare=hare->next;    
    }
    
    while(hare->next!=NULL){
        hare=hare->next;
        turtle=turtle->next;
    }
    // delete(turtle->next);
    turtle->next=turtle->next->next;
return start->next;
}