// Approach: Sort the array and return k & n-kth indices
// Time complexity: O(NlogN)  ; Space complexity: O(1)

// Approach: Create 2 heaps(min and max). Insert all elements. Return top of the heaps after popping k elements
// Time complexity: O(k+(n-k)*log(k))  ; Space complexity: O(k)


// Approach: Use Quicksort partition algo and then just call quicksort on the side where k lies(as we want to find kth smallest/largest element)
// Time complexity: O(N) {T(n)=T(n/2)+n} ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int l,int r){
    int j=l-1;
    int pivot=arr[r];
    
    for(int i=l;i<r;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[r]);
return j+1;
}

int ksmallest(vector<int>& arr,int idx,int l,int r){
    int pivot;
    pivot=partition(arr,l,r);
        
    if(pivot==idx){
        return arr[pivot];
    }else if(pivot>idx){
        return ksmallest(arr,idx,l,pivot-1);
    }else{
        return ksmallest(arr,idx,pivot+1,r);
    }
return -1;
}


vector<int> kthSmallLarge(vector<int>& arr,int n,int k){
    vector<int> ans;
    
	int x1=ksmallest(arr,k-1,0,arr.size()-1);
    int x2=ksmallest(arr,(arr.size()-k),0,arr.size()-1);
    
    ans.push_back(x1);
    ans.push_back(x2);
return ans;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,k;
    int ele;
    vector<int> arr;

    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    vector<int> ans;
    ans=kthSmallLarge(arr,n,k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;    
}