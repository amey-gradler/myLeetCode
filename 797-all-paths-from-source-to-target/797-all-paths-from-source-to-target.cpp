class Solution {
public:
    
    void dfs(int node,int target, vector<int> res,vector<vector<int>> &ans , vector<vector<int>>& graph )
    {
        if(node==target)
        {
            res.push_back(node);
            ans.push_back(res);
            return;
        }
        res.push_back(node);
        for(auto it : graph[node])
        {
            dfs(it,target,res,ans,graph);
        }
        return ;
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int> res;
        int target = graph.size()-1;
        dfs(0,target,res,ans,graph);
        return ans;
        
        
    }
};