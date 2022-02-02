class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    int shortest_pathbfs(vector<vector<int>>& forest,int sr,int sc , int er,int ec){
        if(sr==er && sc==ec) return 0;
        int m = forest.size();
        int n = forest[0].size();
        queue<pair<int,int>> q;
        int step=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty())
        {
            step++;
            int size = q.size();
            while(size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int r = row+dir[i];
                    int c = col+dir[i+1];
                    
                    if(r<0 || r>=m || c<0 || c>=n || forest[r][c]==0 || vis[r][c]==1) continue;
                    if(r==er && c==ec)
                        return step;
                    q.push({r,c});
                    vis[r][c]=1;
                    
                }
                
            }
        }
        
        return -1;
        
    }
    
    
    int cutOffTree(vector<vector<int>>& forest) {
        
        if(forest.size()==0 || forest[0].size()==0)
            return -1;
        
        int m = forest.size();
        int n = forest[0].size();
        
        vector<vector<int>> trees;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(forest[i][j]>1)
                {
                    trees.push_back({forest[i][j],i,j});
                }
            }
        }
        
        sort(trees.begin(),trees.end());
        
        int ans=0;
        int cur_row=0,cur_col=0;
        for(int i=0;i<trees.size();i++)
        {
            int steps = shortest_pathbfs(forest,cur_row,cur_col,trees[i][1],trees[i][2]);
            
            if(steps==-1) return -1;
            ans+=steps;
            cur_row=trees[i][1];
            cur_col=trees[i][2];
        }
            
        return ans;
    }
};