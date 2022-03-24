class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)
            return 0;
//         tabulation logic
        // vector<int> t(n+1);
//         t[0]=0;
//         t[1]=nums[0];
        
//         for(int i=2;i<=n;i++)
//         {
//             t[i]=max(nums[i-1]+t[i-2] , t[i-1]);
//         }
//         return t[n];
        
        
        //space optimized
        // TC- O(n) SC - O(1)
        
        int prev=nums[0];
        int prev2=0;
        int curi=0;
        for(int i=1;i<n;i++)
        {
            int take= nums[i];
            if(i>1) take+=prev2;
            
            int skip = 0+prev;
            
            curi = max(take,skip);
            prev2=prev;
            prev=curi;
            
        }
        return prev;
        
        
        
    }
};