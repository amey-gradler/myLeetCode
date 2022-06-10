class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        //find the floor of an element
        int n = nums.size();
        int low=0;
        int high=n-1;
        int res;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
            {
                res = mid+1;
                low= mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return res;
        
    }
};