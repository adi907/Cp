// Approach: 
// Time complexity: O() ; Space complexity: O()


#include<bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) {
    unordered_map<int,int> mp;
    vector<int> ans;
    int n=arr.size();

    int i;
    for(i=0;i<k;i++){
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());
    int head=0;

    for(i=k;i<n;i++){
        if(mp[arr[head]]==1){
            mp.erase(arr[head]);
        }else{
            mp[arr[head]]--;
        }
        head++;
        mp[arr[i]]++;
        ans.push_back(mp.size());
    }
return ans;
}