// Brute force: Iterate over array, for each element i, traverse all elements j to the right of it and keep track of profit and update maxProfit
// Time complexity: O(N^2); Space complexity: O(1)


// Optimised approach: Iterate over array. Keep updating the min element of array as you keep traversing and calculate profit via (current element-min element) and keep updating maxProfit{initialise it with 0: & return it same as 0 if no profit possible}
// Time complexity: O(N); Space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    int minimum=INT_MAX;
    int maxProfit=0;
    
    for(int i=0;i<prices.size();i++){
        minimum=min(minimum,prices[i]);
        maxProfit=max(maxProfit,prices[i]-minimum);
    }
return maxProfit;
}