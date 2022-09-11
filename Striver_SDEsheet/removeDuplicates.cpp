// Naive approach: Store all elements in hashset. Then place these elements in the array from start and return size of hashset for no. of unique elements
// Time complexity: O(NlogN + N) ; Space complexity: O(N)

// Optimal approach(2 pointer approach): Keep a pointer i before which only unique elements are stored and a pointer j that just iterates over the whole array. Whenvever j encounters a unique element(diff. than one at i) move i fwd & replace value with that of at j's index 
// Time complexity: O(N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
    int i=0;
    for(int j=i+1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    int ans=i+1;
    
    while(i<n){
        arr[++i]=-1;
    }
return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int ele;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<removeDuplicates(arr,n)<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}