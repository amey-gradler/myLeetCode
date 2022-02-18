class Solution {
public:
    int hIndex(vector<int>& nums) {
        
        int n=nums.size();
        int start=0;
        int end= n-1;
        
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[mid]==n-mid)
                return nums[mid];
            else if(nums[mid]<n-mid)
                start=mid+1;
            else
                end=mid-1;
        }
        
        return n-start;
        
        
    }
};