class Solution {
public:
    
    
    int merge(vector<int>& nums, int low,int mid,int high)
    {
        if(low>=high) return 0;
        
        int cnt=0;
        int j = mid+1;
        
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]>2LL*nums[j])
                j++;
            cnt += (j-(mid+1));
        }
        
        
        int l = low,r=mid+1,size=high-low+1,k=0;
        vector<int> sorted(size);
        
        while(l<=mid && r<=high)
        {
            if(nums[l]<=nums[r])
            {
                sorted[k++] = nums[l++];
            }
            else
            {
                sorted[k++] = nums[r++];
            }
        }
        
        while(l<=mid)
        {
            sorted[k++] = nums[l++];
        }
        
        while(r<=high)
        {
            sorted[k++] = nums[r++];
        }
        
        
        for (k = 0; k < size; k++)
		nums[k + low] = sorted[k];
    
        return cnt;    
        
    }
    
    int mSort(vector<int> & nums,int low,int high)
    {
        int rev_cnt=0;
        int mid = low + (high-low)/2 ;
        
        if(low>=high) return 0;
        
        rev_cnt += mSort(nums,low,mid);
        rev_cnt+= mSort(nums,mid+1,high);
        
        rev_cnt+= merge(nums,low,mid,high);
        
        return rev_cnt;
        
    }
    
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        
        int cnt=0;
        cnt= mSort(nums,0,n-1);
        return cnt;
        
    }
};