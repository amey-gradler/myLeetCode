class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        if(nums.size()==2)
            return nums;
    
        long long int xxory = 0;
        for(int i: nums)
        {
            xxory ^= i;
        }
        
        long long int rsbm = xxory & (-xxory);
        int x=0,y=0;
        
        for(int i : nums)
        {
            if(i & rsbm)
            {
                x^=i;
            }
            else
            {
                y^=i;
            }
        }
        
        vector<int> ans = {x,y};
        return ans;
    }
};