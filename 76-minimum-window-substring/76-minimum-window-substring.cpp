class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        if(n==0) return "";
        if(n<m) return "";
        
        unordered_map<char,int> mp;
        
        for(auto ch : t)
        {
            mp[ch]++;
        }
        
       
        
        int cnt=mp.size();
        
        int mini=INT_MAX;
        int startI=-1;
        
        int i=0,j=0;
        
        while(j<s.length())
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    cnt--;
            }
            
            if(cnt==0)
            {
                
                while(cnt==0)
                {
                    
                    if(j-i+1<mini)
                    {
                        mini=j-i+1;
                        startI=i;
                    }
                    
                    if(mp.find(s[i])!=mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                            cnt++;
                    }
                    i++;
                }
            }
            j++;
        }
        
        if(startI==-1)
            return "";
        return s.substr(startI,mini);
        
        
    }
};