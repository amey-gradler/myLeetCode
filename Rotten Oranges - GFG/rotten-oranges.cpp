// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        int z = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==0)
                    z++;
            }
        }
        
        if(z==n*m)
        {
            //all cells empty
            return 0;
        }
        
        if(q.size()==0)
        {
            //no rotten oranges present
            return -1;
        }
        
        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {-1,0,1,0};
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            int i = p.first;
            int j = p.second;
            
            for(int r=0;r<4;r++)
            {
                int xx = i+dx[r];
                int yy = j+dy[r];
                
                if(xx<0 || xx>=n || yy<0 || yy>=m || grid[xx][yy]!=1)
                    continue;
                
                grid[xx][yy] = grid[i][j]+1;
                q.push({xx,yy});
                
            }
            
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
                    
                ans = max(ans,grid[i][j]);
            }
        }
        
        return ans-2;
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends