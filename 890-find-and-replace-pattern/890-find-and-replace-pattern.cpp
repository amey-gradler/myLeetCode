class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        
        for(auto str : words)
        {
            unordered_map<char,char> mp;
            set<char> st;
            int i;
            for(i=0;i<str.length();i++)
            {
                if(mp.count(str[i])==0)
                {
                    if(st.find(p[i])==st.end())
                    {
                        mp[str[i]] = p[i];
                        st.insert(p[i]);
                    }
                    else break;
                }else{
                    if(mp[str[i]]!=p[i])
                        break;
                }
            }
            
            if(i==str.length())
                ans.push_back(str);
        }
     return ans;   
    }
};