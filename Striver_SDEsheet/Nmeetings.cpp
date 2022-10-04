// Approach: Sort all meetings in accordance to their ending times. Now place the first meeting in result(as it has to take place). Now see other meetings starting time. If greater than previous ending time, add to result & update new ending time as this meeting's ending time
// Time complexity: O(N + NlogN + N); Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

struct meet{
    int starting;
    int ending;
    int pos;
};

bool comparator(struct meet a,struct meet b){
    if(a.ending<b.ending){
        return true;
    }else if(a.ending>b.ending){
        return false;
    }else if(a.pos<b.pos){
        return true;
    }

return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    struct meet a[start.size()];
    for(int i=0;i<start.size();i++){
        a[i].starting=start[i];
        a[i].ending=end[i];
        a[i].pos=i+1;
    }
    
    sort(a,a+start.size(),comparator);
        
    vector<int> res;
    res.push_back(a[0].pos);
    int limit=a[0].ending;
         
    for(int i=1;i<start.size();i++){
        if(a[i].starting>limit){
            limit=a[i].ending;
            res.push_back(a[i].pos);
        }
    }
return res;
}