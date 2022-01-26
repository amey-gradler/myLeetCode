class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n =grid[0].size();
        
        queue<pair<int,int>> q;
        int z=0;
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(grid[r][c]==2)
                    q.emplace(r,c);
                else if(grid[r][c]==0)
                    z++;
            }
        }
        
        if(z==m*n)
            return 0;
        
        if(q.size()==0)
            return -1;
        
        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nr = r+dir[i], nc= c+dir[i+1];
                if(nr<0 || nc<0 || nr==m || nc==n || grid[nr][nc]!=1) continue;
                grid[nr][nc] = grid[r][c]+1;
                q.emplace(nr,nc);
            }
        }
        
        int ans=0;
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(grid[r][c]==1)
                    return -1;
                ans=max(ans,grid[r][c]);
            }
        }
        return ans-2;
        
    }
};