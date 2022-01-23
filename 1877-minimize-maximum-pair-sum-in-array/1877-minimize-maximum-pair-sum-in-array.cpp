class Solution {
public:
    int minPairSum(vector<int>& nums) {
      
        vector<int> arr(100001,0);
        
        for(auto i : nums)
            arr[i]++;
        int l = 0;
        int r = 100000;
        int ans=INT_MIN;
        while(l<=r)
        {
            if(arr[l]==0)
            {
                l++;
                continue;
            }
            if(arr[r]==0)
            {
                r--;
                continue;
            }
            
            if(arr[l]!=0 && arr[r]!=0)
            {
                ans = max(ans,l+r);
                arr[l]--;
                arr[r]--;
            }
            
        }
        return ans;
        
    }
};