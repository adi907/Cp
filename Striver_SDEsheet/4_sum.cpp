// Brute force: Sort array. Make 3nested for loops. for each arr[i],arr[j],arr[k] search the target-(arr[i]+arr[j]+arr[k]). If found add to answer array. At end remove all duplicate entries(use set data structure to store entries)
// Time complexity: O(NlogN + N^3*logN)


// Optimal approach: Sort array. Make 2nested loops. For each arr[i],arr[j] search 2 elements with sume equal to target-(arr[i]+arr[j]). Search these 2 elements via the previous 2-sum algo. To avoid duplicates every time changing i,j,low,high never jump to same valued element of these as previous
// Time complexity: O(NlogN+N^3); Space complexity:O(1) {size of answer array doesnt count}

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int i=0;
    int j;
    
    int low;
    int high;
    
    long long int newtarget;
    
    vector<vector<int>> result;
    
    if(nums.size()<4){
        return result;
    }
    
    sort(nums.begin(),nums.end());
    
    while(i<nums.size()-3){
        j=i+1;
        while(j<nums.size()-2){
            low=j+1;
            high=nums.size()-1;
            
            newtarget=(long long int)target-(long long int)(nums[i]+nums[j]);
            
            while(low<high){
                if((long long int)(nums[low]+nums[high])==newtarget){
                    vector<int>sol;
                    sol.push_back(nums[i]);
                    sol.push_back(nums[j]);
                    sol.push_back(nums[low]);
                    sol.push_back(nums[high]);
                    result.push_back(sol);
                    
                    int key1=nums[low];
                    int key2=nums[high];
                    
                    do{
                        low++;
                    }while(nums[low]==key1 && low<high);
                    do{
                        high--;
                    }while(nums[high]==key2 && low<high);
                }else if((long long int)(nums[low]+nums[high])<newtarget){
                    int key=nums[low];
                    do{
                        low++;
                    }while(nums[low]==key && low<high);
                }else{
                    int key=nums[high];
                    do{
                        high--;
                    }while(nums[high]==key && low<high);
                }
            }
            int key=nums[j];
            do{
                j++;
            }while(nums[j]==key && j<nums.size()-2);
        }
        int key=nums[i];
        do{
            i++;
        }while(nums[i]==key && i<nums.size()-1);
    }
return result;
}