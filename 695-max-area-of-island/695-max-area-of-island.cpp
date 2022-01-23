class Solution {
public:
    int rows;
    int cols;

    int dfs(int i,int j,vector<vector<int>> &grid,int a=0)
    {
        if(i<0 || j<0 || i==rows || j==cols)
            return 0;
        if(grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        a++;
        a+=dfs(i+1,j,grid);
        a+=dfs(i-1,j,grid);
        a+=dfs(i,j+1,grid);
        a+=dfs(i,j-1,grid);

        return a;
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