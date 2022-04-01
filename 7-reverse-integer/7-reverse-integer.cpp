class Solution {
public:
    int reverse(int x) {
        
        int flag = 1;
        if(x==0)
            return x;
        if(x<0)
            flag=-1;
        
        x = abs(x);
        int res=0;
        while(x>0)
        {
            int d = x%10;
            // if res*10> INT_MAx  || res*10 + d > INT_MAX return 0;
            if(INT_MAX/10 < res || INT_MAX-d < res*10)
                return 0;
            res = res*10 + d;
            x=x/10;
        }
        
        return res*flag;
        
        
    }
};