// Approach: Create array of size m+n and push the sorted array in it via Merge sort method and then return median
// Time complexity: O(M+N)  ; Space complexity:  O(M+N)

// Approach: Do same merge sort but instead of storing in array keep counter. And when counter =median position return values
// Time complexity: O(M+N)  ; Space complexity:  O(1)


// Approach: see notebook (and always take smaller array first)
// Time complexity: O(log(min(M,N)))  ; Space complexity:  O(1)

#include<bits/stdc++.h>
using namespace std;

double median(vector<int> a, vector<int> b){
    if(a.size()>b.size()){ //reduces search space as well as gets rid of an error ( Lets say smaller array has only 1 element and larger array has 10 elements. count of each half would be 6. If i have to take 0 elements from my larger array, then I'll have to take (6-0 = 6) elements from my smaller array but we dont have that many elements in the smaller array. That's why always take the smaller array and perform binary search starting with low=0 and high=no. of elements in smaller array)
        return median(b,a);
    }
    int n1=a.size();
    int n2=b.size();
    int low=0;
    int high=a.size();//high isnt the index, but no. of elements chosen(i.e why no a.size()-1)
    int cut1,cut2,l1,l2,r1,r2;

    while(low<=high){
        cut1=(low+high)/2;//tells no. of elements to take from 1st array
        cut2=((n1+n2+1)/2)-cut1; //n1+n2+1 coz no matter odd or even no. of elements, give same ans

        l1= cut1==0 ? INT_MIN : a[cut1-1];
        l2= cut2==0 ? INT_MIN : b[cut2-1];
        r1= cut1==n1 ? INT_MAX : a[cut1];
        r2= cut2==n2 ? INT_MAX : b[cut2];

        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0;
            }else{
                return max(l1,l2);
            }
        }else if(l1>r2){
            high=cut1-1;//reduce no. of elements taken from 1st array
        }else{
            low=cut1+1;//increases no. of elements taken from 1st array
        }

    }
return 0.0;
}