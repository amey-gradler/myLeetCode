class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int idx = abs(nums[i])-1;
            
            if(nums[idx]>0)
                nums[idx] *= -1;
            else
                return idx+1;
            
        }
        
       return 0; 
    }
};