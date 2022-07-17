class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int l1,l2;
        vector<int> vec;
        l1=nums1.size();
        l2=nums2.size();
        int i=0;
        int k=0;
        while(i<l1 && k<l2){
            if(nums1[i]>nums2[k]){
                k++;
            }else if(nums1[i]<nums2[k]){
                i++;
            }else{
                vec.push_back(nums1[i]);
                i++;
                k++;
            }
        }
        //removing duplicate elements
        vector<int>::iterator it;
        it = unique(vec.begin(), vec.end());
        vec.resize(distance(vec.begin(), it));
    return vec;
    }
};
