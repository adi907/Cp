/* Approach: Think as N* Lru caches {n=no. of frequencies}. Keep count of node and place node in a dll containing all nodes of same count(freq.) Update freqency & change node's Dll acc. to queries. Also keep a curr_size(total count), size(for each dll), capacity, minFreq(minimum freq value that a present node has). In case of size exceeding capacity remove element from minFreq's Dll's end
Time complexity: get : O(1)  ; put : O(1)
Space complexity: O(N+N)
*/

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int key;
    int val;
    int count;
    node* next;
    node*prev;

    node(int k,int v){
        key=k;
        val=v;
        count=1;
    }
};

class dll{
public:
    int size;
    node* head;
    node* tail;
    dll(){
        size=0; // to check if size of list gets 0 to change minFrequency
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void addNode(int k,int v){
        size++;
        node* newnode=new node(k,v);
        node* temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }

    void deleteNode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
        // delete(delnode); dont delete as wont be able to access nodes values after deleting
    }
};

class LFUCache {
    map<int,node*> keynode; //stores all nodes
    map<int,dll*> listFreq; // stores all Dll's corr. to different frequencies
    int minFreq;
    int currSize;
    int capacity;

public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        minFreq=0;
        currSize=0;
    }

    void updateListFreq(node* curr){
        keynode.erase(curr->key);
        listFreq[curr->count]->deleteNode(curr);

        if(curr->count==minFreq && listFreq[minFreq]->size==0){
            minFreq++; //bcz now node is being placed in 1 higher freq. so max rise in minFreq will be by 1
        }

        curr->count+=1;
        if(listFreq.find(curr->count)!=listFreq.end()){
            listFreq[curr->count]->addNode(curr->key,curr->val);
        }else{
            dll* list1=new dll();
            list1->addNode(curr->key,curr->val);
            listFreq[curr->count]=list1;
        }
        keynode[curr->key]=curr;
    }
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            int ans=keynode[key]->val;
            updateListFreq(keynode[key]);
        return ans;
        }
    return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0){//edge case: if capacity ==0
            return;
        }

        if(keynode.find(key)!=keynode.end()){
            keynode[key]->val=value;
            updateListFreq(keynode[key]);
        }else{
            if(currSize==capacity){ //before adding remove last element of minFreq. of list
                keynode.erase(listFreq[minFreq]->tail->prev->key);
                listFreq[minFreq]->deleteNode(listFreq[minFreq]->tail->prev);
                currSize--;
            }
            //now add new element(sets min frequency to 1)
            currSize++;
            minFreq=1;
            if(listFreq.find(minFreq)!=listFreq.end()){
                listFreq[minFreq]->addNode(key,value);
            }else{
                dll* list1=new dll();
                list1->addNode(key,value);
                listFreq[minFreq]=list1;
            }
            keynode[key]=listFreq[minFreq]->head->next;
        }
    }
};