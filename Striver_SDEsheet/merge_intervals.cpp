// Brute Force: Sort array. Iterate over array and for each pair check for all intervals next to it
// Time complexity:O(NlogN+N*N); Space complexity: O(N)


// Optimised approach: Make a new vector. Insert an element from input array at start when its empty. Now iterate over array and keep checking for each element if it overlaps or not. If overlaps update the upper limit of interval kept at the end(if upper limit of current interval greater than existing) otherwise insert a new interval at the end
// Time complexity: O(NlogN + N); Space complexity: O(N)

#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    sort(intervals.begin(),intervals.end());
    
    vector<vector<int>> merged;
    
    for(int i=0;i<intervals.size();i++){
        if(merged.empty()||merged.back()[1]<intervals[i][0]){
            vector<int> vec={intervals[i][0],intervals[i][1]};
            merged.push_back(vec);
        }else{
            merged.back()[1]=max(merged.back()[1],intervals[i][1]);
        }
    }
    
return merged;
}

// My approach:
// Time complexity: O(NlogN+N); Space complexity: O(1)

    void merger(vector<vector<int>> &intervals,int x,int y,int pos){
        intervals[pos][0]=x;
        intervals[pos][1]=y;
    
        intervals.erase(intervals.begin()+pos+1);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
    
        int low=intervals[0][0];
        int high=intervals[0][1];
        
        int i=1;
        while(i<intervals.size()){
            if(low<=intervals[i][1] && high>=intervals[i][0]){
                high=max(high,intervals[i][1]);
                merger(intervals,low,high,i-1);
            }else{
                low=intervals[i][0];
                high=intervals[i][1];
                i++;
            }
        }
    return intervals;
    }
