class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> m(n,vector<int> (n,0));
        
        int i1=0,j1=0;
        int i2=n-1,j2=n-1;
        int x=1;
        while(i1<=i2 && j1<=j2)
        {
            //left to right
            for(int i=j1;i<=j2;i++)
                m[i1][i] = x++;
            
            //top to bottom
            for(int i=i1+1;i<=i2;i++)
                m[i][j2] = x++;
            
            if(i1<i2 && j1<j2)
            {
                
            //right to left
            for(int i=j2-1;i>=j1;i--)
                m[i2][i]= x++;
            
            //bottom up
            for(int i=i2-1;i>i1;i--)
                m[i][j1]=x++;
            }
            
            i1++;
            i2--;
            j1++;
            j2--;
            
        }
        return m;
        
    }
};