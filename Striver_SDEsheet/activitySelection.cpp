// Approach: Sort all activities in accordance to their ending times. Now place the first activity in result(as it has to take place). Now see other activities' starting time. If greater than previous ending time, add to result & update new ending time as this meeting's ending time
// Time complexity: O(N + NlogN + N); Space complexity:O(1)

#include<bits/stdc++.h>
using namespace std;

struct activity{
    int start;
    int end;
};

bool comparator(struct activity a,struct activity b){
    if(a.end<b.end){
        return true;
    }
return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish){
    int n=start.size();
    struct activity m[n];
    for(int i=0;i<start.size();i++){
        m[i].start=start[i];
        m[i].end=finish[i];
    }
    
    sort(m,m+n,comparator);
    
    int count=1;
    
    int limit=m[0].end;
    for(int i=1;i<n;i++){
        if(m[i].start>=limit){
            count++;
            limit=m[i].end;
        }
    }
    
return count;
}