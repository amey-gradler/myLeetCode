class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        //maximum sum subarray with unique elements;
        
        int n = nums.size();
        
        int i=0;
        int j=0;
        int sum=0;
        
        int res=0;
        
        int fi,fj;
        unordered_map<int,int> mp;
        
        while(j<n)
        {
            sum+=nums[j];
            mp[nums[j]]++;
            
            if(j-i+1==mp.size())
            {
                res=max(res,sum);
                fi=i;
                fj=j;
            }
            else if(j-i+1>mp.size())
            {
                while(j-i+1>mp.size())
                {
                    sum-=nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                    i++;
                }
                
                 
                
            }
            
            j++;
            
        }
        
    
        
        return res;
        
        
        
        
    }
};