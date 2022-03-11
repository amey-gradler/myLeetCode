class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size();
        int bsp= prices[0]*-1;
        int ssp = 0;
        
        for(int i=1;i<n;i++)
        {
            bsp = max(bsp , ssp-prices[i]);
            
            ssp = max(ssp , bsp+prices[i]-fee);
            
        }
        
        return ssp;
        
    }
};