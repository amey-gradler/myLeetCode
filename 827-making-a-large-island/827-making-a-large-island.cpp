class Solution {
public:
    vector<int> dx = {0,-1,0,1};
    vector<int> dy = {-1,0,1,0};
    int n;
    int solve(int i,int j,vector<vector<int>>& grid,int id)
    {
        if(i<0 || j<0 || i==n || j==n || grid[i][j]!=1) return 0;
        
        grid[i][j] = id;
        
        return 1 + solve(i,j-1,grid,id) + solve(i-1,j,grid,id) + solve(i,j+1,grid,id)+solve(i+1,j,grid,id); 
    }
    
    bool checkValid(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i==n || j==n) return false;
        return true;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        
        n = grid.size();
        int id=2;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[id] = solve(i,j,grid,id);
                id++;
            }
        }
        
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int sum=0;
                    set<int> s;
                    for(int k=0;k<4;k++)
                    {
                        
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if(checkValid(xx,yy,grid) && grid[xx][yy]>1 &&                                 s.find(grid[xx][yy])==s.end())
                        {
                            s.insert(grid[xx][yy]);
                            sum+=mp[grid[xx][yy]];
                        }
                        
                    }
                   
                    maxi = max(maxi,sum+1);
                }
            }
        }
        
        return maxi==INT_MIN ? n*n : maxi; 
        
    }
};