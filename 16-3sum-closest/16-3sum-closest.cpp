class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int closest=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1])
                continue;
            
            int front=i+1;
            int back=n-1;
            while(front<back)
            {
                int sum = nums[i]+nums[front]+nums[back];
                
                if(sum>target)
                {
                    if(sum-target<closest)
                    {
                        closest = sum-target;
                        ans=sum;
                    }
                    back--;
                }
                else if(sum<target)
                {
                    if(target-sum<closest)
                    {
                        closest=target-sum;
                        ans=sum;
                    }
                    front++;
                }
                else{
                    return sum;
                }
                
                
            }
            
        }
         return ans;
        
    }
};