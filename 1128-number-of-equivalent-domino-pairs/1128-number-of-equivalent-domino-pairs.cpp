class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        map<vector<int>,int> mp;
        
        int cnt=0;
        for(int i=0;i<dominoes.size();i++)
        {
            
            if(mp.find(dominoes[i]) != mp.end() )
            {
                cnt+=mp[dominoes[i]];
            }
            
            
            int x = dominoes[i][1] ;
            int y = dominoes[i][0] ;
            if(x!=y)
            {
                vector<int> s = {x,y};
            
            if(mp.find(s) != mp.end())
            {
                cnt+=mp[s];
            }
            }
            
            
            mp[dominoes[i]]++;
            
        }
        return cnt;
    }
};