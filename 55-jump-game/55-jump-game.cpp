class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int step=nums[0];
        for(int i=0;i<n;i++)
        {
            step--;
            if(step<0)
                return false;
            if(nums[i]>step)
                step=nums[i];
        }
        
        return true;
        
    }
};