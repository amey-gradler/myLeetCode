class Solution {
public:
    
    int count(vector<int> & nums,int bound)
    {
        int cnt=0;
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=bound)
                cnt++;
            else
                cnt=0;
            ans+=cnt;
        }
        return ans;
    }
    
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        return count(nums,right)-count(nums,left-1);
    }
};