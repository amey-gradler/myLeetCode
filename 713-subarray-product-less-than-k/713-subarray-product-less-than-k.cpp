class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k==0) return 0;
        long long p=1;
        long long res=0;
        long long n = nums.size();
        
        for(int i=0,j=0;j<n;j++)
        {
            p=p*nums[j];
            
            while(i<=j && p>=k)
            {
                p=p/nums[i++];
            }
            
            res+=(j-i+1);
        }
        
        return res;
        
    }
};