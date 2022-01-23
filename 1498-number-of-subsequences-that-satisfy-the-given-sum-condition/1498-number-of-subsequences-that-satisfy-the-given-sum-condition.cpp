class Solution {
public:
    int mod = 1000000007;
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int l=0;
        int r=n-1;
        int res=0;
        vector<int> pows(n,1);
        
        for(int i=1;i<n;i++){
            pows[i]=(pows[i-1]*2)%mod;
        }
        
        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
            {
                r--;
            }
            else
            {
                int x = pows[r-l];
                res=(res+x)%mod;
                l++;
            }
        }
        return res;
        
        
    }
};