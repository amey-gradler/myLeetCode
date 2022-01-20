class Solution {
public:
    
    int dfs(unordered_map<int,vector<int>>&adjList,int i,vector<int>&informTime)
    {    
        if(adjList[i].size()==0)
            return 0;
        
        int mx=0;
        for(auto it : adjList[i])
        {
           mx= max(mx, dfs(adjList, it, informTime));
        }
        return informTime[i]+mx;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)      {   
        unordered_map<int,vector<int>> adjList;
        
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adjList[manager[i]].push_back(i);
        }
        
        return dfs(adjList,headID,informTime);
    }
};