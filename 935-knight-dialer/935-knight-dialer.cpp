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
        vector<vector<int>> t(10,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<10;i++)
        {
            t[i][n]=solve(i,n,mp,t);
            ans= (ans + t[i][n])%MOD;
        }
        return ans;
        
    }
};