class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> seen;
        seen[0]=1;
        
        int cnt=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(seen[sum-k])
            {
                cnt+=seen[sum-k];
            }
            seen[sum]++;
        }
        
        return cnt;
    }
};