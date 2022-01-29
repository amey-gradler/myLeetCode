class Solution {
public:
    
    int parent[201];
    int rank [201];
    int numberOfComponents=0;
    void makesSet(int n)
    {
        parent[0]=-1;
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    
    void unionFind(int u,int v)
    {
        u = findParent(u);
        v= findParent(v);
        
        if(u==v)
            return;
        
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[v]<rank[u])
        {
            parent[v]=u;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }
        numberOfComponents--;
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        makesSet(n);
        numberOfComponents=n;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(i!=j && isConnected[i][j])
                {
                    unionFind(i+1,j+1);
                }
            }
        }
        
        return numberOfComponents;
        
    }
};