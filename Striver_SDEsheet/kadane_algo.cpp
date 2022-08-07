// APPROACH: iterate array from start. Each time keep updating sum upto there and keep comparing with maxsum. If sum goes below 0; reset it with 0
// Time complexity: O(N); Space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long int maxsum=INT_MIN;//use it as 0; if in case of all negatives in array 0 is required as output instead of actual answer
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxsum){
            maxsum=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
return maxsum;
}