// Approach: If key string smaller make it equal/larger to other string. Then apply Rolling hash(rabin karp) and check if substring present. Do this 2 times. If not present increment string by 1more of original(check for start & end adjustment){also see notebook}
// Time complexity: avg=O(N+M) , best=O(NM)  ;Space complexity: O(max(N,M))

#include<bits/stdc++.h>
using namespace std;

int pow26(int p){
    int ans=1;
    int base=26;
    int primenum=5381;

    while(p!=0){
        if(p%2==0){
            base*=base;
            base=base%primenum;
            p/=2;
        }else{
            ans=ans*base;
            ans=ans%primenum;
            p-=1;
        }
    }
return ans%primenum;
}

bool rollingHash(string a,string b){
    if(a.size()<b.size()){
        return false;
    }
    int primenum=5381;
    int m=a.size();
    int n=b.size();

    int h=pow26(n-1);

    int hashkey=0;
    int hashcheck=0;

    for(int i=0;i<n;i++){
        hashkey=((hashkey*26)+(int)(b[i]-96))%primenum;
        hashcheck=((hashcheck*26)+(int)(a[i]-96))%primenum;
    }

    if(hashcheck==hashkey){
        //do spurious hit check
        int k=0;
        for(k=0;k<n;k++){
            if(b[k]!=a[k]){
                break;
            }
        }
        if(k==n){
            return true;
        }
        
    }

    for(int i=n;i<m;i++){
        int keyremov=(int)(a[i-n]-96)*h;
        hashcheck=(26*(hashcheck-keyremov)+(int)(a[i]-96))%primenum;
        if(hashcheck<0){ // if keyremove makes value negative turn it back positive
            hashcheck=hashcheck+primenum;
        }
        if(hashcheck==hashkey){
            //do spurious hit check
            int k=0;
            for(k=0;k<n;k++){
                if(b[k]!=a[i-n+1+k]){
                    break;
                }
            }
            if(k==n){
                return true;
            }
        }
    }
return false;
}

int repeatedStringMatch(string a, string b) {
    if(b.size()==0){
        return 0; // a has to be used 0 times to get b="" as substring
    }
    
    string anew="";
    int cnt=0;

    while(anew.size()<b.size()){ // keep doing until size of a is smaller than b(as b cant be substring till that point)
        anew+=a;
        cnt++;
    }

    for(int i=0;i<2;i++){ // do check 2 times(1 for start & 1 for end adjustment like if substring starts 1 awayjust from start/end etc)
        if(rollingHash(anew,b)){
            return cnt;
        }else{
            anew+=a;
            cnt++;
        }
    }
return -1;
}