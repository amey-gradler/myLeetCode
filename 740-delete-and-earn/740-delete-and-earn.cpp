class Solution {
public:
    
    int solve(int i,vector<int> &nums,int n,vector<int> &t)
    {
        if(i==n)
        {
            return 0;
        }
        
        if(t[i]!=0)
            return t[i];
        
        int x=nums[i];
        int j=i;
        int sum=0;
        
        while(j<n && nums[j]==x)
        {
            sum+=x;
            j++;
        }
        
        while(j<n && nums[j]==(x+1))
        {
            j++;
        }
        
        t[i]=max(sum+solve(j,nums,n,t),solve(i+1,nums,n,t) );
        return t[i];
        
        
    }
    
    
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> t (n,0);
        
        return solve(0,nums,n,t);
        
    }
};