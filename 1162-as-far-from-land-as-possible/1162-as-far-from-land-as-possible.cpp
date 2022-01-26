class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    int maxDistance(vector<vector<int>>& grid) {
        
        int m= grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        
        //push all land nodes in queue to do bfs
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(grid[r][c]==1)
                    q.emplace(r,c);
            }
        }
        
        //no water
        if(q.size()==m*n)
            return -1;
        
        while(!q.empty())
        {
            auto [r,c] =q.front();
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nr= r+dir[i] , nc = c+dir[i+1];
                if(nr<0 || nc<0 || nr==m || nc==n || grid[nr][nc]!=0) continue;
                grid[nr][nc] = grid[r][c]+1;
                q.emplace(nr,nc);
            }   
        }
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans = max(ans, *max_element(grid[i].begin(),grid[i].end()));
        }
            
        return ans-1;
    }
};