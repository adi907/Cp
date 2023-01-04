// Approach: Create 2 halves. 1 containing elements smaller/equal to median stored in max heap, other containing greater than median stored in min heap. Median will be max of 1st half or avg. of (max+min)of the 2 halves resp.
// Time complexity: O(NlogN) ; Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int>lhalf;
    priority_queue<int,vector<int>,greater<int>>rhalf;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(lhalf.size()==0 || num<=lhalf.top()){
            lhalf.push(num);
        }else{
            rhalf.push(num);
        }

        int lsize=lhalf.size();
        int rsize=rhalf.size();

        if(lsize-rsize>1){
            int k=lhalf.top();
            lhalf.pop();
            rhalf.push(k);
        }else if(rsize>lsize){
            int k=rhalf.top();
            rhalf.pop();
            lhalf.push(k);
        }
    }
    
    double findMedian() {
        int lsize=lhalf.size();
        int rsize=rhalf.size();

        double ans;

        if((lsize+rsize)%2==0){
            ans=(double)(lhalf.top()+rhalf.top())/2.00;
            return ans;
        }else{
            ans=(double)lhalf.top();
            return ans;
        }
    }
};