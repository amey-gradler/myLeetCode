// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n,vector<int> (m,0));
	    
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
                    q.push({i,j});
                else
                    ans[i][j] = INT_MAX;
	        }
	    }
	    
	    vector<int> dx = {0,-1,0,1};
	    vector<int> dy = {-1,0,1,0};
	    
	    while(!q.empty())
	    {
	        auto p = q.front();
	        q.pop();
	        
	        int pi = p.first;
	        int pj = p.second;
	        
	        for(int i=0;i<4;i++)
	        {
	            int xx = pi+dx[i];
	            int yy = pj+dy[i];
	            
	            if(xx<0 || xx>=n || yy<0 || yy>=m)
	                continue;
	           
	            if(ans[pi][pj]+1<ans[xx][yy])
	            {
	                ans[xx][yy] = ans[pi][pj]+1;
	                q.push({xx,yy});
	            }
	           
	        }
	        
	    }
	    
	    return ans;
	    
	    
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends