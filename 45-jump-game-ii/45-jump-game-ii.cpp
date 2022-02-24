class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int i=0, lastJumpPos=0,maxReachable=0;
        int jumps=0;
        
        while(lastJumpPos<n-1)
        {
            maxReachable = max(maxReachable,i+nums[i]);
            
            if(i==lastJumpPos)
            {
                lastJumpPos=maxReachable;
                jumps++;
            }
            i++;
        }
        return jumps;
        
    }
};