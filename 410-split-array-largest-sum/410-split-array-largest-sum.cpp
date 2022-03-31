class Solution {
public:
    int find(int m, int s, int e, int n,vector<int>&csum,int dp[51][1001])
    {
        if(m == 1)
        {
            return dp[m][e] = csum[n-1] - csum[s];
        }
        if(e == n-1)
        {
            return dp[m][e] = csum[e];
        }
        if(dp[m][e] != -1)
            return dp[m][e];
        int finalAns = INT_MAX;
        for(int i = e;i<n-1;i++)
        {
            int sum = csum[i]-csum[s];
            int t =  find(m-1,i,i+1,n,csum,dp);
            
            int ans =max(sum,t);
            finalAns = min(finalAns,ans);
        }
        return dp[m][e] = finalAns;
    }
    int splitArray(vector<int>& nums, int m) {
        vector<int>csum ;
        csum.push_back(0);
        csum.push_back(nums[0]);
        int sum = nums[0];
        if(nums.size() == 1)
            return nums[0];
        int dp[51][1001];
        memset(dp,-1,sizeof(dp));
        for(int i = 1;i<nums.size();i++)
        {
            
            sum+= nums[i];
            csum.push_back(sum);
        }
        int n = csum.size();
        int  ans = find(m,0,1,n,csum,dp);
        return ans;
    }
};