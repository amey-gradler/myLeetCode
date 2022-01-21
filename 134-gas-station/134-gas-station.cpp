class Solution {
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int sum=0;
        int balance =0;
        int startIdx=0;
        for(int i=0;i<n;i++)
        {
            sum+=gas[i]-cost[i];
            balance+=gas[i]-cost[i];
            
            if(balance<0)
            {
                balance=0;
                startIdx=i+1;
            }
            
        }
        
        if(sum<0)
            return -1;
        return startIdx;
    }
};