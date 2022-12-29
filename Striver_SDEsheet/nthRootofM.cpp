// Approach: Initialize low and high as 1 & m. Then keep calculating mid element and its power of n. Acc. to it reset low and high(keep care of assigning low & hig=mid(not mid-1 cuz it will skip many decimal points) and iterate until low & high almost same(not exactly same but differ by just 10^-6))
// Time complexity: O(logN*(log2(m*10^6))) {between 1 & m: m*10^6 decimal points and each time doing logN to calculate power} ; Space complexity: O(1)

#include <bits/stdc++.h> 
using namespace std;

double multiplier(double num,int n){
    double ans=1.00;
    while(n!=0){
        if(n%2==0){
            num*=num;
            n/=2;
        }else{
            ans*=num;
            n--;
        }
    }
return ans;
}//takes logN time(better than simply iterating till power O(N))


double findNthRootOfM(int n, int m) {
	double low=0.0;
    double high=(double)m;
    double differ=1e-7;
    
    while(high-low>differ){
        double mid=(low+high)/2.00;
        double mul=multiplier(mid,n);
        if(mul<(double)m){
            low=mid;
        }else if(mul>(double)m){
            high=mid;
        }else{
            return mid;
        }
    }
return low;
}