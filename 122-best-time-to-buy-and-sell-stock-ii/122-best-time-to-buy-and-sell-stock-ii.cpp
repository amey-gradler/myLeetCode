class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        int buyidx=0,sellidx=0;
        int profit=0;
        
        while(buyidx<n && sellidx<n)
        {
            while(buyidx<n-1 && prices[buyidx+1]<prices[buyidx])
                buyidx++;
            
            sellidx= buyidx;
            
            while(sellidx<n-1 && prices[sellidx+1]>prices[sellidx])
                sellidx++;
            
            profit+=prices[sellidx] - prices[buyidx];
            buyidx=sellidx+1;
            
        }
        return profit;
        
    }
};