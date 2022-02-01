class Solution {
public:
    
    map<string , vector<pair<string,double>>> adjList;
    
    
    pair<bool,double> search(string &a,string &b,unordered_set<string> &visited,double val)
    {
    
        if(visited.count(a)==0)
        {
            
            visited.insert(a);
            for(auto p : adjList[a])
                {
                    double temp = val*p.second;
                    if(p.first == b)
                        return make_pair(true,temp);
                    auto result = search(p.first,b,visited,temp);
                    if(result.first)
                    {
                        return result;
                    }
                }
        }
        return make_pair(false,-1.0);
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i=0; i<equations.size();i++)
        {
        
            adjList[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            
            adjList[equations[i][1]].push_back(make_pair(equations[i][0], 1.0/values[i]));
            
        }
        
        vector<double> ans;
        
        for(auto p : queries)
        {
            unordered_set<string> visited;
            
            if(p[0]==p[1] && adjList.count(p[0])!=0)
            {
                ans.push_back(1.0);
            }else
            {
                auto x = search(p[0],p[1],visited,1.0);
                ans.push_back(x.second); //pushesh -1 if not possible else pushes value;   
            }
            
        }
        
        
        return ans;
    }
};