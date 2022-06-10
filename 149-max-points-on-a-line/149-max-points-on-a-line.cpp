class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int maxi=0;
        int n = points.size();
        if(n<3)
            return n;
        for(int i=0;i<n-maxi-1;i++)
        {
            unordered_map<long double,int> mp;
            int x1 = points[i][0];
            int y1 = points[i][1];
            int i_max=0;
            for(int j=i+1;j<n;j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                long double slope;
                if(x2==x1)
                    slope=INT_MAX;
                else
                    slope = (long double)(y2-y1)/(long double)(x2-x1);
                if(mp[slope]==0)
                    mp[slope]=1;
                else
                    mp[slope]++;
                
                if(i_max<mp[slope])
                    i_max = mp[slope];
                
            }
            
            maxi = max(maxi,i_max);
            mp.clear();
            
        }
        
        return maxi+1;
    }
};