class Cordinate{
    public:
        int x;
        int y;
        int len;
        Cordinate(int x,int y,int len)
        {
            this->x =x;
            this->y=y;
            this->len=len;
        }
};

class Solution {
public:
    vector<int> dx = {0,1,1,1,0,-1,-1,-1};
    vector<int> dy = {1,1,0,-1,-1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0]==1)
            return -1;
        
        int ans=INT_MAX;
        queue<Cordinate> q;
        q.push(Cordinate(0,0,1));
        
        while(!q.empty())
        {
            Cordinate c = q.front();
            q.pop();
            
            if(c.x==m-1 and c.y==n-1)
                ans=min(ans,c.len);
            
            for(int i=0;i<8;i++)
            {
                int x = c.x + dx[i];
                int y = c.y + dy[i];
                if(x<0 || y<0 || x==m || y==n || grid[x][y]!=0 ) continue;
                
                grid[x][y]=1;
                int len = c.len+1;
                q.push(Cordinate(x,y,len));
            }
                
        }
        
        return ans==INT_MAX?-1:ans;
    }
};