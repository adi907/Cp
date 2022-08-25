// Approach: Iterate both LL from start and store sums in new LL(keep dummy node). Keep track of sum & carry.Carry=sum/10 & sum=sum%10. If 1 of the LL ends iterate another and still keep track of carry
// Time complexity: O(max(m,n)); Space complexity: O(max(m,n)+1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* start=new ListNode();
    ListNode* temp=start;
    int sum=0;
    int carry=0;
    
    while(l1!=NULL && l2!=NULL){
        sum=carry+l1->val+l2->val;
        
        carry=sum/10;
        sum=sum%10;
        
        temp->next=new ListNode(sum);
        temp=temp->next;
        
        l1=l1->next;
        l2=l2->next;
    }
    
    while(l1!=NULL){
        sum=carry+l1->val;
        
        carry=sum/10;
        sum=sum%10;
        
        temp->next=new ListNode(sum);
        temp=temp->next;
        l1=l1->next;
    }
    while(l2!=NULL){
        sum=carry+l2->val;
        
        carry=sum/10;
        sum=sum%10;
        
        temp->next=new ListNode(sum);
        temp=temp->next;
        l2=l2->next;
    }
    
    if(carry!=0){
        temp->next=new ListNode(carry);
    }
return start->next;
}

// Another approach: In-place addition
// Time complexity: O(m+n+ max(m,n)); Space complexity: O(1)
// Problem: Manipulating the data set

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    auto node = l1;
    int c1 = 0, c2 = 0; // Length of l1 and l2 respectively

    while(node){
        c1++;
        node = node->next;
    }

    node = l2;
    while (node){
        c2++;
        node = node->next;
    }

    // swap if the length of l2 is greater than l1
    if (c2 > c1)
        swap(l1, l2);

    auto head = l1; // head of the result list
    int carry = 0;

    while (l1 || l2) {
        int val = l2 ? l2->val : 0; // if l2 is null, then val is 0
        l1->val = l1->val + val + carry;

        // if there is overflow, i.e sum becomes 2 digits
        if (l1->val > 9) {
            carry = l1->val / 10;
            l1->val = l1->val % 10;
        }
        else {
            carry = 0; // reset value to 0 if there is no overflow
        }

        // If there is still carry remaining at the last element, then add a new node with value as carry
        if (!l1->next && carry > 0) {
            node = new ListNode(carry);
            l1->next = node;
            break; // break is required as there will be an unnecessary iteration due to addition of new node
        }

        l1 = l1->next;
        if (l2) l2 = l2->next;
    }

return head; // return the head of the result list
}