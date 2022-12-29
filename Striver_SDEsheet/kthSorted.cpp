// Approach: Do Merge sort but instead of storing in array keep a counter which keeps count. When counter reaches k return 
// Time complexity: O(N)  ; Space complexity: O(1)


// Approach: Same as previous ques.(Median of 2sorted array) just this time also take care of edge cases regarding low and high pointer value
// Time complexity: O(log(min(m,n)))  ; Space complexity: O(1)

#include <bits/stdc++.h> 
using namespace std; 

int kSorted(vector<int> &row1, vector<int> &row2, int m, int n, int k){
    if(row1.size()>row2.size()){
        return kSorted(row2,row1,n,m,k);
    }
    
    int n1=row1.size();
    int n2=row2.size();
    
    int low=max(0,k-n2);//if total no. of elements to be taken in left half greater than total element in array2 then we cant assign low as 0, we need min. of k-n2 elements from array1 compulsilory
    int high=min(k,n1);//if total no. of elements to be taken in left half smaller than total elements in array1 then we cant take all elements of array1. Just at max k
    int mid;
    
    int cut1,cut2;
    int l1,l2,r1,r2;
    
    while(low<=high){
        mid=(low+high)/2;
        cut1=mid;
        cut2=k-cut1;
        
        l1= (cut1<=0)? INT_MIN:row1[cut1-1];
        l2= (cut2<=0)? INT_MIN:row2[cut2-1];
        r1= (cut1==n1)? INT_MAX:row1[cut1];
        r2= (cut2==n2)? INT_MAX:row2[cut2];
        
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }else if(l1>r2){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
return -1;   
}