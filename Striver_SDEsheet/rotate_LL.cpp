// Naive approach: For each k, find the last element from the list then move it to the first.
// Time complexity:O(N*N) ; Space complexity: O(1)


// Optimal approach: Make LL circular and calculate length of LL with it. Then iterate (len-k)times{take k%len if k is larger than LL}. Break the LL from there and make the node after it as new head
// Time complexity:O(N+N); Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        
        ListNode* start=head;
        int count=1;
        
        while(start->next!=NULL){
            count++;
            start=start->next;
        }
        start->next=head;
        start=head;
        
        k=k%count;
        int travel=count-k;
        
        for(int i=1;i<travel;i++){
            start=start->next;
        }
        
        ListNode* temp=start->next;
        start->next=NULL;
        
return temp;
}