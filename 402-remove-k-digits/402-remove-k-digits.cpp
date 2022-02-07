class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        s.push(num[0]);
        for(int i=1;i<num.length();i++)
        {
            char ch = num[i];
            while(s.size() && s.top()>ch && k)
            {
                s.pop();
                k--;
            }
            
            if(s.size() || ch!='0')
                s.push(ch);
        }
        
        
        while(s.size() && k--)
        {
            s.pop();
        }
        string ans="";
        if(s.size()==0)
            return "0";
        else
        {
            while(s.size())
            {
                ans=s.top()+ans;
                s.pop();
            }
        }
        return ans;
    }
};