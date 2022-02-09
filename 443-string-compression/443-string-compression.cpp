class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size();
        string s="";
        if(n==1)
            return 1;
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            while(i<n-1 && chars[i]==chars[i+1])
            {
                i++;
                cnt++;
            }
            if(cnt>1)
                s+=chars[i]+to_string(cnt);
            else
                s+=chars[i];
        }
        chars.resize(s.length());
        for(int i=0;i<s.length();i++)
        {
            chars[i]=s[i];
        }
        
        return s.length();
    }
};