// Appraoch: Recurse until the head pointer moves null. Merge sort each list from the last.
// Time complexity: ;Space complexity:O()

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* mergeLL(Node* a,Node* b){
    Node* dummy=new Node(0);
    Node* res=dummy;
    
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            dummy->child=a;
            dummy=dummy->child;
            a=a->child;
        }else{
            dummy->child=b;
            dummy=dummy->child;
            b=b->child;
        }
        dummy->next=NULL;//do this just bcz otherwise it give TLE in 1 case
    }
    
    if(a!=NULL){
        dummy->child=a;
    }
    if(b!=NULL){
        dummy->child=b;
    }
return res->child;
}

Node* flattenLinkedList(Node* head){
	if(head==NULL||head->next==NULL){
        return head;
    }
    
    head->next=flattenLinkedList(head->next);
    head=mergeLL(head,head->next);   
return head;
}
