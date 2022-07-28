class Solution {
public:
    
    bool solve(int i,vector<int>&nums,int t,vector<vector<int>>&dp)
    {
        if(t==0)
            return true;
        
        if(i==0)
            return nums[i]==t;
        
        if(dp[i][t]!=-1)
            return dp[i][t];
        
        if(nums[i]<=t)
        {
            return dp[i][t] = solve(i-1,nums,t-nums[i],dp) || solve(i-1,nums,t,dp);
        }
        else
            return dp[i][t]= solve(i-1,nums,t,dp);
        return false;
        
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i: nums)
            sum+=i;
        if(sum%2!=0)
            return false;
        
        sum=sum/2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,nums,sum,dp);
    }
};