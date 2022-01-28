class Solution {
public:
    
    vector<string> solve(int n)
    {
        if(n==1)
        {
            vector<string> res = {"0","1"};
            return res;
        }
        
        vector<string> rres = solve(n-1);
        vector<string> mres;
        
        for(int i=0;i<rres.size();i++)
        {
            mres.push_back("0"+rres[i]);
        }
        
        for(int i=rres.size()-1;i>=0;i--)
        {
            mres.push_back("1"+rres[i]);
        }
        
        return mres;
        
    }
    
    
    
    vector<int> grayCode(int n) {
     
        if(n==1)
        {
            vector<int> res = {0,1};
            return res;
        }
        
        
        vector<string> ans = solve(n);
        vector<int> res;
        for(string s : ans)
        {
            res.push_back(stoi(s,0,2));
        }
        return res;
        
    }
};