class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return 1;
        int prevBig=INT_MIN;
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            
            if(nums[i]<nums[i-1])
            {
                if(cnt>=1)
                    return false;
                if(i-2>=0)
                {
                      if(nums[i-2]<=nums[i])
                    nums[i-1]=nums[i-2];
                else
                    nums[i]=nums[i-1];
                }
                 else 
                {
                nums[i-1]=nums[i];
                }
                cnt++;                
            }
           
            
        }
        return true;
        
    }
};