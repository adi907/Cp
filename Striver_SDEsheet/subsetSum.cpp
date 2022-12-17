// Approach: Traverse through the array and for each index solve for two arrays, one where you pick the element,i.e add the element to the sum or don’t pick and move to the next element, recursively, until the base condition. Here when you reach the end of the array is the base condition
// Time complexity: O(2^n + 2^n log(2^n)) {Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n))}; Space complexity: O(2^n) {for storing subset sums, since 2^n subsets can be generated for an array of size}

#include <bits/stdc++.h> 
using namespace std;

void helper(vector<int>& num,vector<int>& res,int i,int csum){
    if(i==num.size()-1){
        res.push_back(csum);
        res.push_back(csum+num[i]);
        return;
    }
    helper(num,res,i+1,csum);
    helper(num,res,i+1,csum+num[i]);
}

vector<int> subsetSum(vector<int> &num){
    vector<int> res;
    helper(num,res,0,0);
    sort(res.begin(),res.end());
return res;
}