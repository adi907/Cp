// Approach: Recursion, make all possible case and find min. distance of each. Return max of all those min distances
// Time complexity:O(exponential) ; Space complexity: O()


// Brute force Approach: Check for all possible distances from 1 to (largest-smallest)distance and see if its possible to accomodate the no. of cows in distances which are equal or greater to given distance{always assign cow1 to first stall only}
// Time complexity:O(N^2) ; Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

/*
bool isPossible(vector<int>positions,int c,int dist){
    int k=positions[0];
    c--;
    for(int i=1;i<positions.size();i++){
        if(positions[i]-k>=dist){
            c--;
            k=positions[i];
            if(!c){
                return true;
            }
        }
    }
return false;
}

int chessTournament(vector<int> positions,int n,int c){
	sort(positions.begin(),positions.end());
    int a=positions.size();
    int ans=0;
    
    for(int i=1;i<=positions[a-1]-positions[0];i++){
        if(isPossible(positions,c,i)){
            ans=i;
        }
        else{
            break;
        }
    }
return ans;
}
*/

// Optimal approach: Instead of calling all possible distances, use Binary search instead, low=1 to high=(farthest-closest)stall. And if possible,try for higher value each time and finally return high
// Time complexity: O(NlogN) ; Space complexity: O(1)

bool isPossible(vector<int>positions,int c,int dist){
    int lastPos=positions[0];  //always assign cow1 to first stall only
    c--;
    for(int i=1;i<positions.size();i++){
        if(positions[i]-lastPos>=dist){
            c--;
            lastPos=positions[i];
            if(!c){
                return true;
            }
        }
    }
return false;
}

int chessTournament(vector<int> positions,int n,int c){
	sort(positions.begin(),positions.end());
    int a=positions.size();
    
    int low=0;int high=positions[a-1]-positions[0];
    int mid;

    while(low<=high){
        mid=(low+high)>>1;
        if(isPossible(positions,c,mid)){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

return high;//bcz this time to break loop, low will reach in dir. of higher distance. which is not possible and high will stay at correct place
}