#define MOD 1000000007; 

class Solution {
public:
    
    int solve(int i,int n,unordered_map<int,vector<int>> &mp , vector<vector<int>> &t)
    {
        if(n==1)
            return 1;
        
        if(t[i][n]!=-1)
            return t[i][n];
        
        int ans=0;
        for(auto it : mp[i])
        {
            t[it][n-1] = solve(it,n-1,mp,t) ;
            ans= (ans + t[it][n-1])%MOD;
        }
        
        return ans;
    }
    
    
    int knightDialer(int n) {
        unordered_map<int,vector<int>> mp;
        mp[0]={4,6};
        mp[1] = {6,8};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4] = {0,3,9};
        mp[5] = {};
        mp[6] = {0,1,7};
        mp[7] = {6,2};
        mp[8] = {1,3};
        mp[9] = {2,4};
        
        // int t[10][n+1];
        
//         for(int i=0;i<10;i++)
//         {
//             t[i][1]=1;
//         }
        
//         for(int j=2;j<n+1;j++)
//         {   
//             for(int i=0;i<10;i++)
//             {
//                 vector<int> v;
//                 v = mp[i];
//                 int ans=0;
//                 for(auto it : v)
//                 {
//                     ans = (ans + t[it][j-1])%MOD;
//                 }
//                 t[i][j] = ans;
//                 ans=0;
//             }
//         }
        
//         int ans=0;
//         for(int i= 0;i<10;i++)
//         {
//             ans = (ans + t[i][n])%MOD;
//             cout<<t[i][n]<<endl;
//         }
        
        int ans=0;
        vector<vector<int>> t(10,vector<int>(n+1,-1));
        for(int i= 0;i<10;i++)
        {
            ans = (ans + solve(i,n,mp,t))%MOD;
            // cout<<t[i][n]<<endl;
        }
        
        return ans;
        
    }
};