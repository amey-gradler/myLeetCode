class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int> ans(queries.size(),0);
        
        for(int i=0;i<queries.size();i++)
        {
            int x1=queries[i][0];
            int y1=queries[i][1];
            int r=queries[i][2];
            int cnt=0;
            for(int j=0;j<points.size();j++)
            {
                
                int x2= points[j][0];
                int y2=points[j][1];
                
                int term1 = pow(x2-x1,2);
                int term2 = pow(y2-y1,2);
                
                double d = sqrt(term1+term2);
                
                if(d<=r)
                {
 
                    cnt++;
                }
                    
                    
            }
            ans[i] = cnt;
        }
        
        return ans;
        
        
    }
};