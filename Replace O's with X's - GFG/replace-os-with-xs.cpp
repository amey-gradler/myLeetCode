// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:


    void dfs(int i,int j,int n,int m,vector<vector<char>> &mat)
    {
        if(i<0 || i==n || j<0 || j==m || mat[i][j]!='O')
            return;
        
        mat[i][j]='#';
        
        dfs(i,j-1,n,m,mat);
        dfs(i-1,j,n,m,mat);
        dfs(i,j+1,n,m,mat);
        dfs(i+1,j,n,m,mat);
        return;
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        //first and last col
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O')
                dfs(i,0,n,m,mat);
            if(mat[i][m-1]=='O')
                dfs(i,m-1,n,m,mat);
        }
        
        
        //first and last row
        {
            for(int i=0;i<m;i++)
            {
                if(mat[0][i]=='O')
                    dfs(0,i,n,m,mat);
                if(mat[n-1][i]=='O')
                    dfs(n-1,i,n,m,mat);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O')
                    mat[i][j]='X';
                if(mat[i][j]=='#')
                    mat[i][j]='O';
            }
        }
        
        return mat;
        
        
        
        
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends