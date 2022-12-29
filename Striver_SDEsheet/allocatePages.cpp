// Approach: By recursion
// Time complexity:Exponential  ; Space complexity: O()



// Approach: Keep low & high as min. and max. possible pages that can be assigned. Then via mid keep finding whether its possible to allocate those pages to n student. If possible, go for better sol. otherwise increase no. of pages for each student so they can be accomodated
// Time complexity: O(NlogN)  ; Space complexity: O(1)

#include <bits/stdc++.h> 
using namespace std; 

bool isPossible(int barrier,vector<int>time,int n){
    int days=1;
    int Tn=0;

    for(int i=0;i<time.size();i++){  
        if((Tn+time[i])<=barrier){
            Tn+=time[i];
        }else{
            days++;
            // Tn=0;
            // Tn+=time[i]; just simply write
            Tn=time[i];
        }
    }

    if(days>n){
        return false;
    }
return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time){
    int low=INT_MIN;
    int high=0;
    int mid;
    
    for(int i=0;i<time.size();i++){
        if(time[i]>low){
            low=time[i];
        }
        high+=time[i];
    }

    while(low<=high){
        mid=(low+high)/2;
        if(isPossible(mid,time,n)){
            high=mid-1;
        }else{
            low=mid+1;
        }

    }

return (long long int)low;
}