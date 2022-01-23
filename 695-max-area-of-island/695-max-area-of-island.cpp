class Solution {
public:
    int rows;
    int cols;

    int dfs(int i,int j,vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i==rows || j==cols)
            return 0;
        if(grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        return 1+dfs(i+1,j,grid)+dfs(i-1,j,grid) +dfs(i,j+1,grid)+dfs(i,j-1,grid);

        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        rows=grid.size();
        cols = grid[0].size();
        int maxArea = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1)
                {
                int area = dfs(i,j,grid);
                cout<<area<<" ";
                maxArea = max(maxArea,area);
                }
            }
        }
        
        return maxArea;
    }
};