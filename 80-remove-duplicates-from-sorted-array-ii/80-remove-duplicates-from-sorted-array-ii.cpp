class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n= nums.size();
        if(n<=2)
            return n;
        
        int i=1,j=1,cnt=1;
        while(j<n)
        {
            if(nums[j]!=nums[j-1])
            {
                cnt=1;
                nums[i]=nums[j];
                i++;
            }
            else
            {
                if(cnt<2)
                {
                    nums[i]=nums[j];
                    i++;
                    cnt++;
                }
            }
            j++;
        }
        
        return i;
        
    }
};