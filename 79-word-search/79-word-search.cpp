class Solution {
public:
    int rows;
    int cols;
    int n;
    bool dfs(int i,int j ,vector<vector<char>> &board , string word,int ctr)
{
	if(ctr==n)
        return true;
    if(i<0 || j<0 || i==rows || j==cols)
        return false;
        
    if(word[ctr]==board[i][j])
    {
        board[i][j]='#';
        bool res = dfs(i-1,j,board,word,ctr+1) || dfs(i+1,j,board,word,ctr+1) || dfs(i,j-1,board,word,ctr+1) || dfs(i,j+1,board,word,ctr+1);
        board[i][j]=word[ctr];
        return res;
    }else
    {
        return false;
    }
    
}
    bool exist(vector<vector<char>>& board, string word) {
    rows=board.size();
	cols = board[0].size();
    n=word.size();
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(board[i][j]==word[0] && dfs(i,j,board,word,0))
                return true;
		}
	}
	
	return false;
    }
};