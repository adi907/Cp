// Pick the 2 unique elements of the array

#include<bits/stdc++.h>
using namespace std;
int checkbit(int n,int pos){
    return ((n & (1<<pos))!=0);
}

void unique(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^arr[i];
    }//calculates total xorsum which is the xor of 2 unique numbers
    int tempxor=xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){//checks where bit 1 exists in xorsum
        setbit=xorsum & 1;
        pos++;
        xorsum=xorsum>>1;
    }
    int newxor=0;
    for(int i=0;i<n;i++){
        if(checkbit(arr[i],pos-1)==1){//checks all numbers of array at pos-1 whether the bit exists
            newxor=newxor^arr[i];
        }
    }
    cout<<newxor<<endl; 
    cout<<(tempxor^newxor);
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
    unique(arr,n);
return 0;
}
