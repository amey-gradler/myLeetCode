class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int m= matrix.size();
        int n=matrix[0].size();
        int i;
        for(i=0;i<m;i++){
            if(target<= matrix[i][n-1]){
                break;
            }
        }
        if(i==m)
            return false;
        
        int s=0;
        int e =n-1;
        
        while(s<=e){
            int mid= (s+e)/2;
            
            if(target==matrix[i][mid]){
                return true;
            }
            else if(target>matrix[i][mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};