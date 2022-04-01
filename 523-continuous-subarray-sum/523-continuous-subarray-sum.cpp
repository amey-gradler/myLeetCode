class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        mp[0]=-1;
        int n = nums.size();
        if(n<2)
            return false;
        int csum=0;
        
        for(int i=0;i<n;i++)
        {
            csum += nums[i];
            csum  = csum%k;
            
            if(mp.count(csum))
            {
                if(i - mp[csum] >1)
                {
                    return true;
                }
            }
            else{
                mp[csum]=i;
            }
            
        }
        
        return false;
    }
};