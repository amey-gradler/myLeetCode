typedef long long int ll;

class Solution {
public:
    
    
    ll solve(vector<int> arr)
    {
        int n=arr.size();
        int prev=arr[0];
        int prev2=0;
        
        for(int i=1;i<n;i++)
        {
            int take=arr[i];
            if(i>1) take+=prev2;
            
            int skip = 0+prev;
            
            int curi=max(take,skip);
            
            prev2=prev;
            prev=curi;
            
        }
        
        return prev;
        
    }
    
    int rob(vector<int>& nums) {
        
        ll n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> temp1,temp2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        
        return max(solve(temp1),solve(temp2));
        
        
    }
};