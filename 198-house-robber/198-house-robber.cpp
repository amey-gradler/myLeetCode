class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> t(n+1);
        t[0]=0;
        t[1]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            t[i+1]=max(nums[i]+t[i-1] , t[i]);
        }
        return t[n];
        
    }
};