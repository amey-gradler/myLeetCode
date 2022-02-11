class Solution {
public:
    
    void solve(int i,int n,string curStr,vector<string> &ans,int open,int close)
    {
        if(curStr.length()==2*n)
        {
            ans.push_back(curStr);
            return;
        }
        
        if(open>0)
        {
            solve(i+1,n,curStr+'(',ans,open-1,close);
        }
        if(open<close)
        {
            solve(i+1,n,curStr+')',ans,open,close-1);
        }
        
        return;
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curStr="";
        int open=n;
        int close=n;
        solve(0,n,curStr,ans,open,close);
        return ans;
        
    }
};