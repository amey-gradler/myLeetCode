class Solution {
public:
    
    int rows;
    int cols;
    
    
    void dfs(int i,int j, vector<vector<char>> &board)
    {
        if(i<0 || j<0 || i==rows || j==cols || board[i][j]!='O')
            return;
        
        board[i][j]='#';
        
        dfs(i-1,j,board);
        dfs(i,j-1,board);
        dfs(i+1,j,board);
        dfs(i,j+1,board);
        
        return;
    }
    
    
    void solve(vector<vector<char>>& board) {
        
        rows =board.size();
        cols=board[0].size();
        
        for(int i=0;i<rows;i++)
        {
            if(board[i][0]=='O')
                dfs(i,0,board);
            if(board[i][cols-1]=='O')
                dfs(i,cols-1,board);
        }
        
        for(int j=0;j<cols;j++)
        {
            if(board[0][j]=='O')
                dfs(0,j,board);
            if(board[rows-1][j]=='O')
                dfs(rows-1,j,board);
        }
        
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
                
            }
        }
        
        return;
    }
};