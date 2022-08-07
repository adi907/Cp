// Naive approach: Keep frequency array. The index with value 0: missing, index with value 2: repating
// Time complexity: O(N+N); Space complexity: O(N)

// Optimised approach: Using negation i.e travel from i->arr[i]->arr[arr[i]]... while updating each visited place to -1. When you reach back to another -1, the no. that sent you there is the repeating number. And the index which does not gets set to -1 is missing
// Time complexity:O(N+N); Space complexity: O(1)
// Cons: Interviewer doesn't like manipulation to data set

// Optimal approach: via Maths(Sn-S[array]= Missing - Repating; SQUARESUMn-SQUARESUM[array]= MISSING^2 - REPEATING^2)
// Time complexity: O(N); Space complexity:O(1)
// Problem: Sum of Squares can lead upto very long values

#include<bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    long long int len=arr.size();
	long long int s=len*(len+1)/2;
    long long int p=len*(len+1)*(2*len+1)/6;
    
    long long int si=0;
    long long int pi=0;
	for(int i=0;i<len;i++){
        si+=(long long int)arr[i];
        pi+=(long long int)arr[i]*(long long int)arr[i];
    }
    
    long long int missing;
    long long int repeating;
    
    long long int m_r=s-si;
    long long int mplusr=(p-pi)/m_r;
    
    missing=(m_r+mplusr)/2;
    repeating =mplusr-missing;
    
return {missing,repeating};
}

// BEST APPROACH(XOR METHOD): First do xorsum of all elements of array, then do xor of this with actual n-elements(from 1 to n); the resultant is equal to MISSING(xor)REPEATING. Now check which of the bit of this result is set to 1. Iterate all elements of array and classify into 2 buckets; 1 with set bit and another with not. Now also separate 1 to N also in these buckets. Xorsum both the buckets. One of those is MISSING and other is REPEATING
// Time complexity: O(N+N+N+N+N); Space complexity: O(1)

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	int xorsum=n;
    
    for(int i=0;i<n;i++){
        xorsum=xorsum^arr[i];
        xorsum=xorsum^i;
    }
    
    //Get rightmost setbit
    int setbit_value=xorsum & (~(xorsum)+1);//always in 2's power:2,4,8,16,... its log can tell position of rightmost setbit
    
    int x=0;//BUCKET1: with setbit set
    int y=0;//BUCKET2: with setbit not set
    
    for(int i=0;i<n;i++){
        if(setbit_value & arr[i]){
            x=x^arr[i];
        }else{
            y=y^arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(setbit_value & i){
            x=x^i;
        }else{
            y=y^i;
        }
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return {y,x};
        }
    }
return {x,y};
}
