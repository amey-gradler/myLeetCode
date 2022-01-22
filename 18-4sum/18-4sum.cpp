class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>res;
        if(n<4) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]>target-nums[i+2]-nums[i+1]) break;
            if(nums[i]+nums[n-3]<target-nums[n-2]-nums[n-1]) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]>target-nums[j+1]-nums[j+2]) break;
                if(nums[i]+nums[j]<target - nums[n-2]-nums[n-1] ) continue;
                int left = j+1;
                int right = n-1;
                
                while(left<right)
                {
                    if(nums[i]+nums[j]<target-nums[left]-nums[right]) left++;
                    else if(nums[i]+nums[j]>target-nums[left]-nums[right]) right--;
                    else{
                        res.push_back(vector<int> {nums[i],nums[j],nums[left],nums[right]});
                        
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        left++;
                        right--;
                        
                        
                    }
                }
                
            }
            
        }
        return res;
        
    }
};