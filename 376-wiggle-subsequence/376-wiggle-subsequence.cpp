class Solution {
public:
    
    
    int solve(int i,vector<int>& nums,int prev,vector<int>& dp)
    {
        int n = nums.size();
        if(i==n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=0;
        if(i==n-1)
        {
            if(nums[i]!=prev)
                ans++;
        }
        else if(prev==-1)
        {
            ans += solve(i+1,nums,nums[i],dp);
        }
        else 
        {
            int take=INT_MIN,notTake=INT_MIN;
            if((nums[i]<prev && nums[i]<nums[i+1]) || (nums[i]>prev &&                      nums[i]>nums[i+1])  )
                {
                    //take
                    take = 1+solve(i+1,nums,nums[i],dp);
                }
            notTake= solve(i+1,nums,prev,dp);
            ans = max(take,notTake);
            
        }
        return dp[i]=ans;
        
    }
    
    int wiggleMaxLength(vector<int>& nums) {
     
        int n = nums.size();
        vector<int> dp(n,-1);
        int res = 1+solve(1,nums,nums[0],dp);
        
        res = max(res,solve(1,nums,-1,dp));
        
        return res;
        
        
        
    }
};