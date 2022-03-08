class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> t(n+1);
        t[0]=0;
        t[1]=nums[0];
        
        for(int i=2;i<=n;i++)
        {
            t[i]=max(nums[i-1]+t[i-2] , t[i-1]);
        }
        return t[n];
        
    }
};