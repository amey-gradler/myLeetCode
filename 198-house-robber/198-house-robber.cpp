class Solution {
public:
    
    int solve(int idx,vector<int> &nums,vector<int> &t)
    {
        if(idx>=nums.size())
            return 0;
        if(t[idx]!=-1)
            return t[idx];
        
        
        return t[idx] =max(nums[idx] + solve(idx+2,nums,t), solve(idx+1,nums,t));
        
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        vector<int> t(n+1,-1);
        
        int ans=solve(0,nums,t);
        return ans;
    }
};