class Solution {
public:
    
    int parent[1005];
    int rank[1005];
    
    void makeSet(int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findParent(int u)
    {
        if(u==parent[u])
            return u;
        
        return parent[u] = findParent(parent[u]);
    }
    
    bool checkSameComponents(int u,int v)
    {
        u = findParent(u);
        v= findParent(v);
        
        if(u==v)
            return true;
        return false;
    }
        
    
    bool unionFind(int u,int v)
    {
        u=findParent(u);
        v=findParent(v);
        
        if(checkSameComponents(u,v))
            return false;
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[v]<rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }
        
        return true;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n =edges.size()+1;
        makeSet(n);
        for(auto i : edges)
        {
            bool x = unionFind(i[0],i[1]);
            if(!x)
            {
                return {i[0],i[1]};
            }   
        }
        
        return {0,0};
        
    }
};