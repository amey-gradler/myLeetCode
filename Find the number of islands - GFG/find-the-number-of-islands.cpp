// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int row,int col,vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m= grid[0].size();
        if(row<0 || row>=n || col<0 || col>=m )
        {
            return;
        }
        if(grid[row][col]!='1')
            return;
            
        grid[row][col]='0';
        
        dfs(row,col-1,grid);
         dfs(row-1,col-1,grid);
          dfs(row-1,col,grid);
           dfs(row-1,col+1,grid);
            dfs(row,col+1,grid);
             dfs(row+1,col+1,grid);
              dfs(row+1,col,grid);
               dfs(row+1,col-1,grid);
        return;
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();

        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends