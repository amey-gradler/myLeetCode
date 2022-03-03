class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        if(n<3)
            return 0;
        
        long long cnt=0;
        int i=0;
        int j=1;
        int d = nums[1]-nums[0];
        while(j<n)
        {
            j++;
            if(j>=n)
                break;
            if(nums[j]-nums[j-1]==d)
            {
                if((j-i+1)>=3)
                {
                    cnt+=((j-i+1)-2);
                }
            }
            else
            {
                i=j-1;
                d=nums[j]-nums[i];
            }
            
        }
        return cnt;
        
    }
};