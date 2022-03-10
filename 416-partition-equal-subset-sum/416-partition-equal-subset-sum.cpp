class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i : nums)
            sum+=i;
        if(sum&1)
            return false;
        
        sum=sum>>1; //sum/=2
        int n=nums.size();
        //Initialisation
        int t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    t[i][j]=false;
                if(j==0)
                    t[i][j]=true;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    t[i][j]= t[i-1][j] || t[i-1][j-nums[i-1]];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
        
        
    }
};