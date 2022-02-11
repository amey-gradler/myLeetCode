class Solution {
public:
    
    void solve(int i,string &digits,string curStr,unordered_map<char,string> &mp,vector<string> &ans)
    {
        if(i>=digits.length())
        {
            ans.push_back(curStr);
            return;
        }
        string s=mp[digits[i]];
        for(char ch :  s)
        {
            solve(i+1,digits,curStr+ch,mp,ans);
        }
        
        return;
    }
    
    
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits=="")
            return ans;
        
        string curStr="";
        unordered_map<char,string> mp ;
            mp['2']="abc";
            mp['3']="def";
            mp['4']="ghi";
            mp['5']="jkl";
            mp['6']="mno";
            mp['7']="pqrs";
            mp['8']="tuv";
            mp['9']="wxyz";
        
        
        solve(0,digits,curStr,mp,ans);
        return ans;
        
    }
};