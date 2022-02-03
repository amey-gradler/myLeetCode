class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> nums12;
        
        for(auto i : nums1)
        {
            for(auto j : nums2)
            {
                nums12[i+j]++;
            }
        }
        
        int res=0;
        
        for(auto i : nums3)
        {
            for(auto j: nums4)
            {
                res+= nums12[-i-j];
            }
        }
        return res;
        
    }
};