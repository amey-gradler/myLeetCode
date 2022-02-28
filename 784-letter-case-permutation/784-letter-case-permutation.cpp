class Solution {
public:
    
    void solve(int n,string ip,string op,int i,vector<string> &ans)
    {
        if(i==n)
        {
            ans.push_back(op);
            return;
        }
        char ci=ip[i];
        if(isdigit(ci))
        {
            return solve(n,ip,op+ci,i+1,ans);
        }
        
        ci=tolower(ci);
        solve(n,ip,op+ci,i+1,ans);
        ci=toupper(ci);
        solve(n,ip,op+ci,i+1,ans);
        return ;
        
        
    } 
    vector<string> letterCasePermutation(string s) {
        
        vector<string> ans;
        string str="";
        int n=s.length();
        solve(n,s,str,0,ans);
        return ans;
    }
};