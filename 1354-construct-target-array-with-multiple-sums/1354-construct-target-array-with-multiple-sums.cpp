typedef long long int ll;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<ll> pq;
        
        ll sum=0;
        for(int i : target)
        {
            pq.push(i);
            sum+=i;
        }
        
        ll n = target.size();
        if(n==1) return target[0]==1;
        while(sum>n)
        {
            ll oldSum = pq.top();
            pq.pop();
            ll restOfArrSum = sum-oldSum;
            ll largest2=pq.top();
            ll x = max(1ll,(oldSum-largest2)/restOfArrSum);
            ll oldEle = oldSum-(restOfArrSum*x);
            if(oldEle<=0)
                return false;
            pq.push(oldEle);
            sum=restOfArrSum+oldEle;
        }
        
        if(sum==n)
            return true;
        return false;
        
        
        
    }
};