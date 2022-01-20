class Solution {
public:
    int rows;
    int cols;
    
    void dfs(int i,int j, vector<vector<int>> &grid)
    {
        
        if(i<0 || j<0 || i==rows || j==cols || grid[i][j]!=1)
            return;
        
        grid[i][j]=2;
        
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        return;
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        
         rows=grid.size();
         cols = grid[0].size();
        
        //first to last coloumn
        for(int i=0;i<rows;i++)
        {
            if(grid[i][0]==1)
                dfs(i,0,grid);
            if(grid[i][cols-1]==1)
                dfs(i,cols-1,grid);
        }
        
        //first to last row
        for(int j=0;j<cols;j++)
        {
            if(grid[0][j]==1)
                dfs(0,j,grid);
            if(grid[rows-1][j]==1)
                dfs(rows-1,j,grid);
        }
        
        
        int cnt=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1)
                    cnt++;
            }
        }
        
        return cnt;
        
    }
};