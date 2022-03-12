class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        
        int n = arr.size();
        
        if(k==0 || n==0)
            return 0;
        
        int dp[k+1][n];
        
        //initialization
        for(int i=0;i<k+1;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=0;i<n;i++)
        {
            dp[0][i]=0;
        }
        
        for(int t=1;t<k+1;t++)
        {
            for(int d=1;d<n;d++)
            {
                dp[t][d]= dp[t][d-1];
                
                int mx = INT_MIN;
                for(int pd=0;pd<d;pd++)
                {
                    int prevProfit = dp[t-1][pd];
                    int todayProfit = arr[d]-arr[pd];
                    // mx = max(mx,prevProfit+todayProfit);
                    dp[t][d] = max(dp[t][d],prevProfit+todayProfit);
                }
                
            }
        }
        
        return dp[k][n-1];
        
        
    }
};