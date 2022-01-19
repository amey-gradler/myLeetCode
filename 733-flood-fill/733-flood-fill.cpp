class Solution {
public:
    
    void fill(int sr,int sc,int newColor,int z,vector<vector<int>> &image)
    {
        if(sr<0 || sc<0 || sr==image.size() || sc==image[0].size() || image[sr][sc]!=z)
                return;
        
        image[sr][sc] = newColor;
        fill(sr-1,sc,newColor,z,image);
        fill(sr,sc-1,newColor,z,image);
        fill(sr+1,sc,newColor,z,image);
        fill(sr,sc+1,newColor,z,image);
        
        return;
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int z = image[sr][sc];
        if (image[sr][sc] != newColor)
            fill(sr,sc,newColor,z,image);
        return image;
        
    }
};