// Naive approach:
// Time complexity: O() ; Space complexity: O()

#include<bits/stdc++.h>
using namespace std;

// bool comparator(vector<int>& a,vector<int>& b){
//     if(a[0]<b[0]){
//         return true;
//     }else if(a[0]>b[0]){
//         return false;
//     }else if(a[1]>b[1]){
//         return true;
//     }
// return false;
// }

// int helper(vector<vector<int>> &jobs,int index,int time){
//     if(index>jobs.size()-1){
//         return 0;
//     }
//     int ans=0;
//     if(time<jobs[index][0]){
//         ans=max(jobs[index][1]+helper(jobs,index+1,++time),helper(jobs,index+1,time));
//     }else{
//         ans=helper(jobs,index+1,time);
//     }
// return ans;
// }

// int jobScheduling(vector<vector<int>> &jobs){
//     int n=jobs.size();
//     sort(jobs.begin(),jobs.end(),comparator);
    
//     int ans=helper(jobs,0,0);
// return ans;
// }

// Optimal approach: Sort in descending order of profit. Then iterate array & try to perform each job as close to its deadline as possible so we can accomodate other lower cost jobs in the time before
// Time complexity:O(NlogN + N*M) {M is max_deadline out of all deadlines} ; Space complexity:O(M) 

bool comparator(vector<int> a,vector<int> b){
    if(a[1]>b[1]){
        return true;
    }
return false;
}

int jobScheduling(vector<vector<int>> &jobs){
    sort(jobs.begin(),jobs.end(),comparator);
    
    int cost=0;
    int max_deadline=jobs[0][0];
    for(int i=1;i<jobs.size();i++){
        if(jobs[i][0]>max_deadline){
            max_deadline=jobs[i][0];
        }
    }
    vector<int> res(max_deadline,-1);
    
    for(int i=0;i<jobs.size();i++){
        int j=jobs[i][0]-1;
        while(j>=0 && res[j]!=-1){
            j--;
        }
        if(j!=-1){
            res[j]=i+1;
            cost+=jobs[i][1];    
        }
        
    }
return cost;
}