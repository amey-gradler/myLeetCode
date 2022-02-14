typedef pair<int,char> pc;
class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> mp;
        
        for(char c : s )
        {
            mp[c]++;
        }
        
        
        priority_queue<pc> maxH;
        
        for(auto it : mp)
        {
            maxH.push({it.second,it.first});
        }
        
        int j=0;
        while(maxH.size())
        {
            auto it = maxH.top();
            int freq=it.first;
            char ch = it.second;
            while(freq--)
            {
                s[j]=ch;
                j++;
            }
            maxH.pop();
            
        }
        
        return s;
        
    }
};