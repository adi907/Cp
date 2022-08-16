// Naive approach: Take 2loops, iterate over all possible substrings. Count no. of unique alphabets from start(as soon as repeating element occurs stop count; can use hashset for this)
// Time complexity: O(N*N); Space complexity:O(N){size of hashset to store elements}

// Optimized approach: Take 2 pointers, left and right. Keep pushing alphabets into hashset. If duplicate found, keep moving left to right and deleting from hashset until we've got rid of duplicated element.
// Time complexity:O(N+N){worst case: left & right both have to travel all the elements} ; Space complexity: O(N){size of hashset to store elements}

// Optimal apprach: Take 2 pointers,left and right. Keep pushing all alphabets into hashmap. As soon as right encounters a duplicate that occurs in the range l-r update left to next element of duplicate element's previous occurrence
// Time complexity:O(N); Space complexity: O(N){size of hashmap}

#include<bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input){
    if(!input.size()){
        return 0;
    }
    unordered_map<char,int> ourMap;
    
    int left=0;int right=0;
    
    int maxcount=1;
    
    while(right<input.size()){
        if(ourMap.count(input[right]) && ourMap[input[right]]>=left){
            left=ourMap[input[right]]+1;
        }
        ourMap[input[right]]=right;
        maxcount=max(maxcount,right-left+1);   
        right++; 
    }
return maxcount;
}