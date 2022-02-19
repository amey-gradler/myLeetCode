class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res =INT_MAX , min_n = INT_MAX;
        
        priority_queue<int> pq;
        for(int i: nums)
        {
            i=i%2?i*2:i;
            pq.push(i);
            min_n = min(i,min_n);
        }
        
        while(pq.top()%2==0)
        {
            res=min(res,pq.top()-min_n);
            min_n = min(min_n,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res,pq.top()-min_n);
    }
};