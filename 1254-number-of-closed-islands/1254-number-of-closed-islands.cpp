class Solution {
public:
    int rows;
    int cols;    
    bool dfs(int i,int j ,vector<vector<int>> &grid)
    {
        if(grid[i][j]==1 || grid[i][j]==-1) return true;
        
        if(i<=0 || j<=0 || i==rows-1 || j==cols-1)
            return false;
        
        grid[i][j]=-1;
        
        bool d1 = dfs(i-1,j,grid);
        bool d2= dfs(i+1,j,grid);
        bool d3= dfs(i,j+1,grid);
        bool d4 =dfs(i,j-1,grid);
        
        return d1&&d2&&d3&&d4;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        rows=grid.size();
        cols =grid[0].size();
        
        if(rows==0 || cols==0)
            return 0;
        
        int cnt=0;
        for(int i=1;i<rows-1;i++)
        {
            for(int j=1;j<cols-1;j++)
            {
                
                if(grid[i][j]==0)
                {
                    if(dfs(i,j,grid))
                        cnt++;
                }
            }
        }
        
        return cnt;
    }
};