class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        if(n==0)
            return 0;
        unordered_map<char,int> mp;
        int ans= 1;
        
        int i=0,j=0;
        while(j<n)
        {
            if(mp[s[j]]==0)
            {
                
                mp[s[j]]++;

            }
            else{
                mp[s[j]]++;
                while(mp[s[j]]!=1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                
            }
            ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
        
    }
};