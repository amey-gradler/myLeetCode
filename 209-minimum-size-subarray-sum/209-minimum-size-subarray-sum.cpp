class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        long long sum=0;
        int minL =INT_MAX;
        int i=0,j=0;
        int n=nums.size();
        
        while(j<n)
        {
            sum=sum+nums[j];
            j++;
            {
                while(sum>=target)
                {
                    minL = min(minL,j-i);
                    sum=sum-nums[i];
                    i++;
                }
            }
        }
        
        if(minL==INT_MAX)
            return 0;
        return minL;
        
        
        
    }
};