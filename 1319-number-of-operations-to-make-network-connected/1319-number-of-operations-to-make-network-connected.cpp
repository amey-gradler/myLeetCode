class Solution {
public:
    
    int parent[100005];
    int rank[100005];
    
    int number;
    int redundant;
    
    void makeSet(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findParent(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionF(int u,int v)
    {
        u =findParent(u);
        v=findParent(v);
        if(u==v)
        {
            redundant++;
        }
        else{
                  number--;
        }
        
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[v]<rank[u])
        {
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
        
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        number=n;
        redundant=0;
        makeSet(n);
        for(auto i : connections)
        {
            unionF(i[0],i[1]);
        }
        
        
        cout<<redundant<<" "<<number;
        if(number-1 <= redundant)
            return number-1;
        return -1;
        
    }
};