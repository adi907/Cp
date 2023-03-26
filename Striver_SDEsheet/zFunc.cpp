// Approach: By rabin Karp algo. Rolling hash. Keep taking modulus by prime(5381)
// Time complexity: O(M) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
#define primenum 5381

int pow26(int p){
    int base=26;
    int ans=1;
    while(p!=0){
        if(p%2){
            ans=base*ans;
            ans=ans%primenum;
            p--;
        }else{
            base=base*base;
            base=base%primenum;
            p/=2;
        }
    }
return ans%primenum;
}

int strStr(string haystack, string needle) {
    int m=haystack.size();
    int n=needle.size();
    int h=pow26(n-1);

    if(m<n){
        return -1;
    }

    int hashkey=0;
    int hashcheck=0;

    for(int i=0;i<needle.size();i++){
        hashkey=((hashkey*26)+(int)(needle[i]-96))%primenum;
        hashcheck=((hashcheck*26)+(int)(haystack[i]-96))%primenum;
    }

    if(hashkey==hashcheck){
        //do spurious hit check
        int k;
        for(k=0;k<n;k++){
            if(haystack[k]!=needle[k]){
                break;
            }
        }
        if(k==n){
            return 0;
        }
    }

    for(int i=0;i<m-n;i++){
        int keyremov=(int)(haystack[i]-96)*h;
        hashcheck=((hashcheck-keyremov)*26+(int)(haystack[i+n]-96))%primenum;

        if(hashcheck<0)hashcheck+=primenum;
        if(hashkey==hashcheck){
            //do spurious hit check
            int k;int l=0;
            for(k=i+1;k<=i+n;k++){
                if(haystack[k]!=needle[l]){
                    break;
                }
                l++;
            }
            if(k==i+n+1){
                return i+1;
            }
        }
    }
return -1;
}