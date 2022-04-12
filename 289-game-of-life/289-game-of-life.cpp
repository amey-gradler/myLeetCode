class Solution {
public:
    
    int cntLive(int i,int j,int m,int n,vector<vector<int>>& board)
    {
        int cnt=0;
        //left
        if(j>0)
        {
            if(board[i][j-1]==1) cnt++;    
        }
        
        //left up
        if(i>0 && j>0)
        {
            if(board[i-1][j-1]) cnt++;
        }
        //top
        if(i>0)
        {
            if(board[i-1][j]) cnt++;
        }
        
        //right up
        if(i>0 && j<n-1)
        {
            if(board[i-1][j+1]) cnt++;
        }
        
        //right
        if(j<n-1)
        {
            if(board[i][j+1]) cnt++;
        }
        
        
        //right down
        if(i<m-1 && j<n-1)
        {
            if(board[i+1][j+1]) cnt++;
        }
        
        
        //down
        if(i<m-1)
        {
            if(board[i+1][j]) cnt++;
        }
        
        //left down
        if(j>0 && i<m-1){
            if(board[i+1][j-1]) cnt++;
        }
        
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> grid(m,vector<int> (n,0));
      
        // cout<<cntLive(m-1,n-1,m,n,board);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt = cntLive(i,j,m,n,board);
                
                if(board[i][j]==1)
                {
                    if(cnt<2)
                        grid[i][j]=0;
                    else if(cnt==2 || cnt==3)
                        grid[i][j]=1;
                    else if(cnt>3)
                        grid[i][j]=0;
                }
                else{
                    if(cnt==3)
                        grid[i][j]=1;
                }
                
            }
        }
        
        board=grid;
        
    }
};