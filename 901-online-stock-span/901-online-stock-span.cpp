class StockSpanner {
public:
    
    stack<pair<int,int>> st1,st2;
    
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        
        if(st1.empty())
        {
            st1.push({price,i});
            i++;
            return 1;
        }
        
        while(!st1.empty() && st1.top().first<=price)
        {
            st1.pop();
        }
        
        int ans;
        if(st1.empty())
        {
            ans=i+1;
        }
        else{
            int j = st1.top().second;
            ans = i-j;
        }
           
        st1.push({price,i});
        i++;
        
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */