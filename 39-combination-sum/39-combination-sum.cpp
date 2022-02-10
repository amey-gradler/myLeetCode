class Solution {
public:
    void solve(int i ,int target, vector<int> & candidates,vector<int> &res,vector<vector<int>> &ans)
    {
        
        if(target==0)
            {
                ans.push_back(res);
                return ;
            }
        if(i>=candidates.size())
        {
            if(target==0)
            {
                ans.push_back(res);
            }
            return ;
        }
        
        if(candidates[i]<=target)
        {
            res.push_back(candidates[i]);
            solve(i,target-candidates[i],candidates,res,ans);
            res.pop_back();
        }
        
        solve(i+1, target,candidates,res,ans);
        return;
        
    }
    
    
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,target,candidates,res,ans);
        
        return ans;
        
    }
};