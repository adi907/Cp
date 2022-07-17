//Using bitwise, find an element that is unique in array where all other elements occur 3 times

#include<bits/stdc++.h>
using namespace std;

int getbit(int n,int pos){
    return ((n & (1<<pos))!=0);
}
int setbit(int n,int pos){
    return (n|(1<<pos));
}
int unique(int arr[],int n){
    int result=0;
    for(int i=0;i<64;i++){//64 bcoz max an int can store is 64bits so for 64 positions we check
        int sum=0;
        for(int j=0;j<n;j++){
            if(getbit(arr[j],i)){
                sum++;
            }
        }
        if(sum %3!=0){//if not divisible by 3, it means that the unique number is included in this and has its bit 1 at i'th position
            result=setbit(result,i);
        }
    }
    return result;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#	endif
    int n,arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   cout<< unique(arr,n);
return 0;
}
