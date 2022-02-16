class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        int start=0;
        int end= nums.size()-1;
        int n = nums.size();
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                return nums[mid];
            else if(nums[mid]<=nums[end])
            {
                end=mid-1;
            }
            else if(nums[start]<=nums[mid]){
                start = mid+1;
            }
            
        }
        
        return -1;
        
    }
};