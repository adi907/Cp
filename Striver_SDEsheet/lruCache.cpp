/* Approach: Use hashmap(to store nodes) and D.L.L(for connnection). Get returns value of node(-1 if not),also places node at start. Put inserts element in cache if it doesnt exist,else places element at start(also take care if size exceeds capacity)

Time complexity: get : O(1)  ; put : O(1)
Space complexity: O(N+N)
*/

#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    class node{
    public:
        int key;
        int val;
        node* prev;
        node* next;
        
        node(int k,int v){
            key=k;
            val=v;
        }
    };
public:
    int cap;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*> ourMap;


    LRUCache(int capacity){
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }

    void addNode(int k,int v){//always added at start
        node* newnode=new node(k,v);
        node* temp=head->next;

        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }

    void deleteNode(node* delNode){//can delete from anywhere as get function places any element at start
        node* delprev=delNode->prev;
        node* delnext=delNode->next;

        delprev->next=delnext;
        delnext->prev=delprev;
        delete(delNode);
    }

    int get(int key){
        if(ourMap.find(key)!=ourMap.end()){
            int ans=ourMap[key]->val;
            deleteNode(ourMap[key]);
            ourMap.erase(key);
            addNode(key,ans);
            ourMap[key]=head->next;

        return ans;
        }
    return -1;
    }

    void put(int key, int value){
        if(ourMap.find(key)!=ourMap.end()){
            deleteNode(ourMap[key]);
            ourMap.erase(key);
        }
        if(ourMap.size()==cap){
            ourMap.erase(tail->prev->key);
            deleteNode(tail->prev);

        }
        addNode(key,value);
        ourMap[key]=head->next;
    }
};