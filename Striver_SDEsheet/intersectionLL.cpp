// Brute force: For each node of LL1, iterate all of LL2 & see if any node address equals to that. If yes, break and return otherwise continue
// Time complexity: O(M*N); Space complexity: O(1)


// Better approach(Hashing): Store all node addresses of any 1 LL in a Hashmap. Then iterate other LL to find if any of the nodes match address kept in map; If yes return 
// Time complexity: O(M+N); Space complexity: O(N)

// Optimized(Difference of Length): Calculate length of both LL(M & N). Traverse the bigger ll (M-N times) so it stands at same point as other LL's starting pt. Now traverse both LL together. When both have same node address return
// Time complexity: O(M+(M-N)+N)=O(2M) {M is bigger LL}; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int findIntersection(ListNode *firstHead, ListNode *secondHead){
    int m=0;
    int n=0;
    
    ListNode* start1=firstHead;
    ListNode* start2=secondHead;
    while(start1!=NULL || start2!=NULL){
        if(start1!=NULL){
            start1=start1->next;
            m++;
        }
        if(start2!=NULL){
            start2=start2->next;
            n++;
        }
    }
    
    int steps=m-n;
    if(steps>0){
        while(steps!=0){
            steps--;
            firstHead=firstHead->next;
        }
    }else{
        while(steps!=0){
            steps++;
            secondHead=secondHead->next;
        }
    }
    
    while(firstHead!=NULL && secondHead!=NULL){
        if(firstHead==secondHead){
            return firstHead->val;
        }
        firstHead=firstHead->next;
        secondHead=secondHead->next;
    }
return -1;
}

// Optimal: Take 1 pointer for each list pointing at their heads resp. Traverse both of them until equal. If any 1 becomes NULL point it to head of other LL. If both become NULL together return -1.
// Intuition: After m step(larger LL size) both pointers will be at same point in LL's(both N nodes away from end). Then we start iterating again. If no intersection both will reach NULL together
// Time complexity: O(M+N); Space complexity: O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* start1=headA;
    ListNode* start2=headB;
    
    while(start1!=NULL || start2!=NULL){
        if(start1==NULL){
            start1=headB;
        }
        if(start2==NULL){
            start2=headA;
        }
        if(start1==start2){
            return start1;
        }
        start1=start1->next;
        start2=start2->next;
    }
return NULL;
}

