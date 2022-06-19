typedef long long int ll;
class Solution {
public:
    
    map<pair<ll,ll>,pair<ll,ll>> dp;
    
    //pair -> max value of leaf node , minSum of all non leaf nodes in that tree
    pair<ll,ll> solve(ll st,ll en,vector<int> &arr)
    {
        
        if(st==en)
        {
            //leaf value condition
            return dp[{st,en}] = {arr[st],0};
        }
        
        if(dp.count({st,en}))
            return dp[{st,en}];
        
        ll maxLeaf = INT_MIN;
        ll minSum = INT_MAX;
        for(ll i=st;i<en;i++)
        {
            //partitioning lead nodes to be either in the left subtree or in the right subtree of root node;
            
            // left-> st to i
            auto left = solve(st,i,arr);
            // right-> i+1 to en
            auto right = solve(i+1,en,arr);
            
            maxLeaf = max(left.first,right.first);
            minSum = min(minSum , left.second+right.second+(left.first*right.first) );
            
        }
        
        return dp[{st,en}] =  {maxLeaf,minSum};
        
        
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        
        return solve(0,n-1,arr).second;
        
    }
};