class Solution {
public:
    
    static bool cmp(string& a,string &b)
    {
        if(a.length()==b.length())
            return b>a;
        else
            return b.length()>a.length();
    }
    
    bool isSubseq(string p,string q)
    {
        int i = 0,j=0;
        int n = p.length();
        while(i<n && j<n-1)
        {
            if(p[i]==q[j])
            {
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        if(j>=n-1) return true;
        return false;
    }
    
    
    int solve(vector<string>& words,int i,vector<int>& visited,vector<int>& dp)
    {   
        visited[i]=true;
        // cout<<words[i]<<" ";
        if(i==0)
            return dp[i]=1;
        
        if(dp[i]!=0)
            return dp[i];
        
        int j=i-1;
        int sz = words[i].length();
        while(j>=0 && words[j].length()==sz)
            j--;
        int res=1;
        // cout<<i;
        while(j>=0 && words[j].length()==sz-1)
        {
            if(isSubseq(words[i],words[j]))
            {
                res = max(res,1+solve(words,j,visited,dp));
            }
            j--;
        }
        return dp[i]=max(dp[i],res);
    }
    
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        
        for(string s : words)
            cout<<s<<" ";
        cout<<endl;
        
        int n = words.size();
        vector<int> vis(n,false);
        vector<int> dp(n,0);
        int i = n-1;
        int txt = words[i].length();
        int ans = 0;
        while(i>=0 )
        {   
            if(vis[i]==0)
            {
                cout<<words[i]<<endl;
            dp[i] = max(dp[i],solve(words,i,vis,dp));
            }
            
            i--;
        }
 
        ans = *max_element(dp.begin(),dp.end());
        return ans;
    }
};