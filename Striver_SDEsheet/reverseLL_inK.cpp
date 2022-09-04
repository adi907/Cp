// Approach: See register
// Time complexity: O(N) Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    if(k==1){
        return head;
    }
    int len=0;
    ListNode* start=head;
    
    while(start!=NULL){
        start=start->next;
        len++;
    }
    start=head;
    
    ListNode* dummy=new ListNode(0,head);
    
    ListNode* pre=dummy;
    ListNode* curr=pre->next;
    ListNode* nex=pre->next->next;
    
    int j=0;
    while((len/k)!=0){
        while(j<k-1){
            curr->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=curr->next;
            j++;
        }
        len-=k;
        j=0;
        if(len/k!=0){
            pre=curr;
            curr=curr->next;
            nex=nex->next;    
        }
        
    }
return dummy->next;
}