typedef long long ll;
class Solution {
public:
    int countOrders(int n) {
        
        ll res=1;
        ll mod=1000000007;
        
        for(int i=1;i<=n;i++)
        {
            //calculate n!
            res*=i;
            
            //avoid stackoverflow
            res%=mod;
            
            // (2*i-1) are the vacant places which we can choose
			// later we have n! permutation of pickup task
			// therefore we have to multiply with n! that we calculated as res.
            res *= (2*i-1);
            
             //avoid stackoverflow
            res%=mod;
            
            
        }
        
        return res%mod;
        
    }
};