class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int max1=amount+1;
        vector<int> t(amount+1,max1);
        t[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(coins[j]<=i)
                    t[i]= min(t[i], t[i-coins[j]] + 1);
            }
        }
        return t[amount]>amount ? -1 : t[amount];
        
    }
};