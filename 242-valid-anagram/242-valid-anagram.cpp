class Solution {
public:
    bool isAnagram(string s, string t) {
       
        if(s.length()!=t.length())
            return false;
        unordered_map<char,int> mp;
        for(char ch : s)
        {
            mp[ch]++;
        }
        
        for(char c : t)
        {
            mp[c]--;
            if(mp[c]==0)
                mp.erase(c);
        }
        
        if(mp.size()==0) return true;
        return false;
    }
};