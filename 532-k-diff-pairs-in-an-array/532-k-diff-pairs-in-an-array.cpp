class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n==0)
            return 0;
        
        map<int,int> mp;
        for(int i : nums)
        {
            mp[i]++;
        }
        int res=0;
        if(k==0)
        {
            for(auto it : mp)
            {
                if(it.second>1)
                    res++;
            }
                
        }
        else
        {
            for(auto it : mp)
            {
                if(mp.find(it.first+k)!=mp.end())
                {
                
                    res++;
                }
                    
            }
        }
        return res;
        
    }
};