class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int ans=INT_MIN;
        int l=1;
        int r=1;
        for(int i=0;i<n;i++)
        {
            // cprod*=nums[i];
            // ans=max(ans,cprod);
            // if(cprod==0)
            //     cprod=1;
            if(l==0)
                l=1;
            if(r==0)
                r=1;
            l=l*nums[i];
            r=r*nums[n-1-i];
            
           
            
            ans = max(ans,max(l,r));
            
            
        }
        
        return ans;
        
    }
};