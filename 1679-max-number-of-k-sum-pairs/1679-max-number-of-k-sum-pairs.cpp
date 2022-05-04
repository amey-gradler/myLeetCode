class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        set<int> s;
        map<int,int> mp;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            s.insert(nums[i]);
        }
        
        int ans=0;
        for(int x : s)
        {
            int y = k-x;
            
            if(y<x)
                break;
            
            if(s.find(y)!=s.end())
            {
                if(x==y)
                {
                    ans += floor(mp[x]/2);
                }
                else
                {
                    ans += min(mp[x],mp[y]);
                }
            }
            
        }
        
        return ans;
        
    }
};