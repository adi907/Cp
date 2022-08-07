#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n){
    int sum=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ans=max(sum,ans);
        if(sum<0){
            sum=0;
        }
    }
    return ans;
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

    /*Circular max subarray sum(i.e array does not end at the end and can be wrapped)
    2 cases:a)When non-contributing wrap at end and start of array.{same as before}. Simply apply Kadane
            b)When contributing wrap{solution given below}
              Max circular subarray possible= Total Sum of array - Sum of non-contributing elements 
              Sum of non-contributing elements=(-ve of array), then apply Kadane's algo*/
    //Find sum by both cases and return the max out  of 2

    int nonwrapsum;//case a
    int wrapsum;//case b

    nonwrapsum=kadane(arr,n);
    int tot=0;
    for(int i=0;i<n;i++){
        tot+=arr[i];
        arr[i]*=-1;
    }
    wrapsum=tot-(-kadane(arr,n));//kadane gets the sum of non-contributing elements which were made positive. Turn them back to negative. And then subtract them from the total sum
    cout<<max(wrapsum,nonwrapsum);
return 0;
}
