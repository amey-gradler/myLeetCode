class Solution {
public:
    
    bool isValid(vector<int> &nums , int n,int k,int mid)
    {
        int s = 1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                s++;
                sum=nums[i];
            }
            if(s>k) return false;
        }
        return true;
        
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();
        
        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);
        
        int res;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
                
            if(isValid(nums,n,m,mid))
            {
                res=mid;
                end = mid-1;
            }
            else
                start=mid+1;
            
        }
        
        return res;
        
    }
};