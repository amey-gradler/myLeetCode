class Solution {
public:
    
    bool dfs(int node,vector<vector<int>> &adjList, vector<int> &color)
    {
        if(color[node]==-1) 
            color[node]=1;
        // cout<<node<<adjList[node].size();
     for(auto it : adjList[node])
       {
         if(color[it]==-1)
             {
                color[it]= 1-color[node];
                if(!dfs(it,adjList,color))
                    return false;
             }
         else if(color[it]==color[node])
                return false;
                
       }
    return true;
        
    }
    
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int> > adjList(n+1,vector<int>(0));
        for(int i=0;i<dislikes.size();i++)
        {
            adjList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjList[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,adjList,color))
                    return false;
            }
        }
        
        return true;
    }
};