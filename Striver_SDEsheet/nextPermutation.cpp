// Brute force: Find all permutations, store them in an array. Find the given permutation order and return 1 next to it
// Time complexity: O(N!*N)


// Optimal approach(Not allowed): By using in-built c++ function

// #include<bits/stdc++.h>
// using namespace std;

int main() {
    vector<int> vec={1,2,4,3};
   
    next_permutation(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
    }  
}

// Optimised approach: Iterate array from back. Find i1: arr[i1]<arr[i1+1]; find i2 from right where arr[i2]>arr[i1]; swap i1 & i2; reverse all elements to right of i1.{see intuition behind this approach on Yt}{take care of edge case when already biggest permutation given; return the smallest}
// Time complexity: O(N+N+N); Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,3,2};
    // int arr[]={5,4,3,2,1};
    int n=3;

    int ind1=-1;
    int ind2;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind1=i;
            break;
        }
    }

    if(ind1==-1){
        // edge case: Greatest permutation-> return smallest permutation
        for(int i=0;i<n/2;i++){
            int temp=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=temp;
        }
        for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
        }

        return 0;
    }else{
        for(int i=n-1;i>ind1;i--){
            if(arr[i]>arr[ind1]){
                ind2=i;
                break;
            }
        }

        int temp=arr[ind1];
        arr[ind1]=arr[ind2];
        arr[ind2]=temp;

        int num_ele=n-(ind1+1);

        for(int i=ind1+1,j=0;i<ind1+1+((n-ind1)/2);i++,j++){
            int temp1=arr[i];
            // cout<<temp1;
            arr[i]=arr[n-1-j];
            arr[n-1-j]=temp1;
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<",";
        }
    }

}
