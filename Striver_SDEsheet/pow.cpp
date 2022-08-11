// Naive approach: To caluclate x^n, run a for loop n times multiplying x and storing in a variable
// Time complexity: O(N); Space complexity: O(1)



// Optimal approach: x^n=(x*x)^n/2{if n is even}; x*(x*x)^n/2{if n is odd} and also if n==0, x=1. Also keep in mind edge cases(like when n<0)
// Time complexity: O(logN); Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    double ans=1.00;
    long long int nn=(long long int)n;
    if(nn<0){
        nn*=-1;
    }
    
    while(nn!=0){
        if(nn%2==0){
            nn/=2;
            x*=x;
        }else{
            ans*=x;
            nn--;
        }
    }
    
    if(n<0){
        ans=(double)1.0/(double)ans;
    } 
return ans;
}

// when asked to return an integer by modulo->keep modulo again and again on both x and ans so that it doesn't exceed limit and store them in long long int initially and convert to int at end while returning

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    long long int ans=1;
    long long int base=x;
    
    while(n!=0){
        if(n%2==0){
            n/=2;
            base=((base%m)*(base%m))%m;
        }else{
            ans=(ans*base)%m;
            n--;
        }
    }
return (int)ans%m;
}