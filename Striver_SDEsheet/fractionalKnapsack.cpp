// Approach: Sort vector on basis of max value per weight. Then keep adding the value of the items until weight of some item exceeds the limit of bag. Then add only the value acc. to part of weight of item that can be accomodated and stop iterating And return the value
// Time complexity: O(NlogN + N) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> a,pair<int,int> b){
    double vpwa=(double)(a.second)/(double)(a.first);
    double vpwb=(double)(b.second)/(double)(b.first);
    
    if(vpwa>vpwb){
        return true;
    }
return false;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w){
    sort(items.begin(),items.end(),comparator);
    double val=0.00;
    double W=(double)w;
    
    for(int i=0;i<items.size();i++){
        if(W>items[i].first){
            W-=(double)items[i].first;
            val+=(double)items[i].second;
        }else{
            val+=W*(double)items[i].second/(double)items[i].first;
            break;
        }
    }
return val;
}
