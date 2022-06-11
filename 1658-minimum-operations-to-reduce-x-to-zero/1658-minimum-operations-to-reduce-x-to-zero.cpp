class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        int arrSum = accumulate(nums.begin(),nums.end(),0);
        
        int k = arrSum-x;
        
        if(k<0)
            return -1;
        if(k==0)
            return n;
        int i=0;
        int j=0;
        
        int sum=0;
        int maxi=-1;
        while(j<n)
        {
            sum+=nums[j];
            
            if(sum==k)
            {
                maxi = max(maxi,j-i+1);
            }
            else if(sum>k)
            {
                while(sum>k)
                {
                    sum-=nums[i];
                    i++;
                }
                 
            if(sum==k)
            {
                maxi = max(maxi,j-i+1);
            }
            }
            j++;
            
        }
        
        if(maxi==-1)
            return -1;
        
        return n-maxi;
        
        
        
    }
};