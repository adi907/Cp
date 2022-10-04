// Naive approach: 
// Time complexity: O(N^2)  ; Space complexity: O(1)

// Optimal Approach: Sort both arrival & departure arrays. Now see if arr[i]>dep[j]; increment num_platform. Otherwise keep decrementing until arrival intersects with someone's departure
// Time complexity: O(NlogN + N + N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    
    int i=1;
    int j=0;
    
    int count=1;
    int maxCount=1;
    
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            count++;
            maxCount=max(count,maxCount);
            i++;
        }else{
            count--;
            j++;
        }
    }

return maxCount;
}