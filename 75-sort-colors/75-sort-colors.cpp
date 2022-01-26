class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int cnt0=0,cnt1=0,cnt2=0;
        
        for(int i : nums)
        {
            if(i==0)
                cnt0++;
            else if(i==1)
                cnt1++;
            else{
                cnt2++;
            }
        }
        
        int i=0;
        while(cnt0--)
        {
            nums[i]=0;
            i++;
        }
        
        while(cnt1--)
        {
            nums[i]=1;
            i++;
        }
        
        while(cnt2--)
        {
            nums[i]=2;
            i++;
        }
        
    }
};