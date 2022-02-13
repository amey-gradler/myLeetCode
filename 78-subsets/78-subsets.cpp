class Solution {
public:
    
    void solve(int i,vector<int> res,vector<int> nums,vector<vector<int>> &ans)
    {
        
        if(i==nums.size())
        {
            ans.push_back(res);
            return;
        }
        
        vector<int> op1=res;
        vector<int> op2=res;
        op1.push_back(nums[i]);
        i++;
        solve(i,op1,nums,ans);
        solve(i,op2,nums,ans);
        
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int>res;
        int i=0;
        solve(i,res,nums,ans);
        
        return ans;
        
    }
};