class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        vector<vector<int>> v;
        
        int n = costs.size();
        for(int i=0;i<n;i++)
        {
            vector<int> a = {costs[i][1]-costs[i][0],costs[i][0],costs[i][1]};
            v.push_back(a);
        }
        
        sort(v.begin(),v.end());
        
        int sum=0;
        
        int j=0;
        while(j<n/2)
        {
            sum+=v[j][2];
            j++;
        }
        
        while(j<n)
        {
            sum+=v[j][1];
            j++;
        }
        return sum;
        
        
    }
};