class Solution {
public:
    
    int solve(int curr,vector<int> &prices,vector<int> &t)
    {
        int n=prices.size();
        if(curr>=n)
            return 0;
        if(t[curr]!=-1)
            return t[curr];
        
        int maxVal=0;
        for(int i=curr+1;i<n;i++)
        {
            //two choices
            //1 - keep the stock in hand and move forward
            //2 - sell the stock and calculate for i+2 pos
            maxVal = max(maxVal, prices[i]-prices[curr] + solve(i+2,prices,t));
        }
        
        //or completly exclude the current element
        maxVal = max(maxVal,solve(curr+1,prices,t));
        t[curr]=maxVal;
        return t[curr];
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        vector<int> t(n+1,-1);
        return solve(0,prices,t);
        
    }
};