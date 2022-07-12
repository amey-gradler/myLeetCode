class Solution {
public:
    bool solve(int i,int bucketNo,int bucketSum,int reqSum,int k,vector<int>& nums,vector<int>& visited)
    {
        
        if(bucketNo==k) return true;
        
        if(bucketSum==reqSum)
        {
            return solve(0,bucketNo+1,0,reqSum,k,nums,visited);
        }
        
        if(bucketSum > reqSum) return false;
        if(i>=nums.size()) return false;
        
        
        if(visited[i])
            return solve(i+1,bucketNo,bucketSum,reqSum,k,nums,visited);
        else{
            
            //pick
            bucketSum += nums[i];
            visited[i]=1;
            bool op1 = solve(i+1,bucketNo,bucketSum,reqSum,k,nums,visited);
            
            //skip
            bucketSum -= nums[i];
            visited[i] = 0;
            bool op2 = solve(i+1,bucketNo,bucketSum,reqSum,k,nums,visited);
            
            return op1 || op2;
        }
        
        
        return false;
        
    }
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    
      int sum =accumulate(nums.begin(),nums.end(),0);
      vector<bool>vis(nums.size(),false);
      if(sum%k!=0)
        return false;
      int s=sum/k;
      sort(begin(nums),end(nums),greater<int>());// For avoid extra calculation
      return is_possible(nums,0,s,k,0,vis);
  }
 bool is_possible(vector<int>&nums,int curr,int sum,int k,int start,vector<bool>&vis)
{
        if(k==1)
            return true;
        if(start>=nums.size()) //This line is important to avoid tle
           return false;
        if(curr==sum)
                return is_possible(nums,0,sum,k-1,0,vis);
    
    for(int i=start;i<nums.size();i++)
    {
        if(vis[i] || nums[i]+curr>sum)
            continue;
        vis[i]=true;
        if(is_possible(nums,curr+nums[i],sum,k,i+1,vis))
            return true;
        vis[i]=false;
    }
    return false;
}
};