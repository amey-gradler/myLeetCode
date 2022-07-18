class Solution {
public:
    
    void paint(int i,int j,vector<vector<int>> & grid)
    {
        if(i<0 || j<0 || i==grid.size() || j ==grid.size() || grid[i][j]!=1)
            return ;
        
        grid[i][j] = 2;
        paint(i,j-1,grid);
        paint(i-1,j,grid);
        paint(i,j+1,grid);
        paint(i+1,j,grid);
        return;
    }
    
    bool expand(int i,int j,vector<vector<int>> & grid,int cl)
    {
         if(i<0 || j<0 || i==grid.size() || j ==grid.size())
            return false;
        
        grid[i][j] = grid[i][j]==0 ? cl +1 : grid[i][j];
        return grid[i][j]==1;
    } 
        
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(f!=0) break;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    paint(i,j,grid);
                    f=1;
                    break;
                }
            }
        }
        
        for(int cl=2;;cl++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==cl && (expand(i,j-1,grid,cl) || expand(i-1,j,grid,cl) || expand(i,j+1,grid,cl) || expand(i+1,j,grid,cl) ))
                    {
                       return cl-2; 
                    }
                }
            }
        }
        
        return -1;
        
        
    }
};