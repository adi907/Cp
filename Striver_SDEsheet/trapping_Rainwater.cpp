// Naive approach: For each index calculate leftMax & rightmax. Then take min of these 2 & subtract with height of current block and keep adding this to value of waterTrapped
// Time complexity: O(N*N); Space complexity: O(1)


// Optimized approach: Take 2 arrays & precalculate the leftmax & rightmax. Now iterate the array again and calculate total waterTrapped by getting min of leftMax & rightMax of that index & subtracting with current height
// Time complexity: O(3*N); Space complexity: O(N+N)

#include<bits/stdc++.h>
using namespace std;

long getTrappedWater(long *arr, int n){
    long* prefix=new long[n];
    long* suffix=new long[n];
    
    prefix[0]=arr[0];
    suffix[n-1]=arr[n-1];
    
    for(int i=1,j=n-2;i<n && j>=0;i++,j--){
        prefix[i]=max(prefix[i-1],arr[i]);
        suffix[j]=max(suffix[j+1],arr[j]);
    }
    
    long waterTrapped=(long)0;
    
    for(int i=0;i<n;i++){
        waterTrapped+=(long)(min(prefix[i],suffix[i])-arr[i]);
    }
return waterTrapped;
}

// Optimal approach: Take 2 pointers(l,r) & lmax,rmax. Further approach in register
// Time complexity:O(N) ; Space complexity: O(1)

int trap(vector<int>& height) {
    int lmax=0;
    int rmax=0;
    
    int l=0;
    int r=height.size()-1;
    int waterTrap=0;
    
    while(l<r){
        if(height[l]<height[r]){
            if(height[l]>=lmax){
                lmax=height[l];
            }else{
                waterTrap+=lmax-height[l];
            }
            l++;
        }else{
            if(height[r]>=rmax){
                rmax=height[r];
            }else{
                waterTrap+=rmax-height[r];
            }
            r--;
        }
    }
return waterTrap;
}
