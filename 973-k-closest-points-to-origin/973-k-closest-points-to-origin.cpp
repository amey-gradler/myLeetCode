typedef pair<double,pair<int,int>> pdi;
class Solution {
public:
    
    double dist(int x, int y)
    {
        return sqrt((x*x)+(y*y));
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        priority_queue<pdi> maxH;
        
        
        for(auto i : points)
        {
            maxH.push({dist(i[0],i[1]) , {i[0],i[1]}});
            if(maxH.size()>k)
            {
                maxH.pop();
            }
            
        }
        
        while(maxH.size())
        {
            ans.push_back({maxH.top().second.first ,maxH.top().second.second});
            maxH.pop(); 
        }
        
        return ans;
        
        
    }
};