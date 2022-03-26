class Solution {
public:
    
//     int solve(int i,int j,vector<vector<int>> &m,vector<vector<int>> &dp)
//     {
//         if(i==m.size()-1)
//             return m[i][j];
        
//         if(dp[i][j]!=INT_MAX)
//             return dp[i][j];
        
//         int down=INT_MAX,ld=INT_MAX,rd=INT_MAX;
        
//         //down
//         down = m[i][j] + solve(i+1,j,m,dp);
        
//         //ld
//         if(j>0)
//         {
//             ld = m[i][j]+solve(i+1,j-1,m,dp);
//         }
        
//         if(j<m.size()-1)
//         {
//             rd = m[i][j] + solve(i+1,j+1,m,dp);
//         }
        
//         return dp[i][j]=min(down,min(ld,rd));
    
//     }
    
    
    int minFallingPathSum(vector<vector<int>>& m) {
        
        int n = m.size();
        
        int ans=INT_MAX;
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        // for(int j=0;j<n;j++)
        // {
        //     ans = min(ans,solve(0,j,matrix,dp));
        // }
        // return ans;
        
        //tabulation
        
//         for(int j=0;j<n;j++)
//         {
//             dp[n-1][j] = m[n-1][j]; 
//         }
        
        
//         for(int i=n-2;i>=0;i--)
//         {
//             for(int j=n-1;j>=0;j--)
//             {
//                 int down=INT_MAX,ld=INT_MAX,rd=INT_MAX;
                
//                 //down;
//                 down =  dp[i+1][j];
//                 //ld
//                 if(j>0)
//                     ld= dp[i+1][j-1];
//                 //rd
//                 if(j<n-1)
//                     rd = dp[i+1][j+1];
                
//                 dp[i][j] = m[i][j] + min(down,min(ld,rd));
                
//             }
//         }
        
//         for(int j=0;j<n;j++)
//         {
//             ans=min(ans,dp[0][j]);
//         }
//         return ans;
        
            //space optimization
        
            vector<int> next (n,0);
            for(int j=0;j<n;j++)
            {
                next[j] = m[n-1][j]; 
            }
        
            for(int i=n-2;i>=0;i--)
            {   
                vector<int> cur(n,0);
                for(int j=n-1;j>=0;j--)
                {
                    int down=INT_MAX,ld=INT_MAX,rd=INT_MAX;
                
                    //down;
                    down =  next[j];
//                 //ld
                    if(j>0)
                        ld= next[j-1];
                // rd
                    if(j<n-1)
                        rd = next[j+1];
                
                cur[j] = m[i][j] + min(down,min(ld,rd));
                }
                next=cur;
            }
        
            for(int j=0;j<n;j++)
            {
                ans=min(ans,next[j]);
            }
        return ans;
            
    }
};