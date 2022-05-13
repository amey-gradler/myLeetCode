class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> freq(k,0);
        freq[0]=1;
        
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            int rem = sum%k;
            if(rem<0) rem+=k;
            
            cnt += freq[rem];
            freq[rem]++;
        }
        
        return cnt;
        
        
    }
};