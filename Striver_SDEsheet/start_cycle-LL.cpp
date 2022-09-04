// Naive approach: Use hashmaps to store all elements addresses. Keep iterating. If an address found present return true. If reach NUll return false
// Time complexity: O(N); Space complexity: O(N)

// Optimal approach(Slow and fast method): Fast iterates 2x than slow. When they collide 1 time reinitialize 1 of them back to start. Now let them iterate with equal speed. The point where they collide again is loop start point. If they reach NULL-no cycle
// Time complexity: O(N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    ListNode* turtle=head;
    ListNode* hare=head;
    
    while(hare!=NULL && hare->next!=NULL){
        turtle=turtle->next;
        hare=hare->next->next;
        
        if(turtle==hare){
            break;
        }
    }
    if(hare==NULL||hare->next==NULL){
        return NULL;
    }
    
    hare=head;
    
    while(hare!=turtle){
        hare=hare->next;
        turtle=turtle->next;
    }
return turtle;
}