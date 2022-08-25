// Approach: Make value of given node equal to next node. Then make connection with next to next node
// Time complexity: O(1); Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node){
    node->val=(node->next)->val;
    node->next=node->next->next;
}