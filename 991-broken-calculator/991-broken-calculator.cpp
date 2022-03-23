class Solution {
public:
    int brokenCalc(int s, int t) {
        
        int ans=0;
        
        while(t>s)
        {
            ans++;
            if(t%2==0)
                t=t/2;
            else
                t+=1;
        }
        ans=ans+(s-t);
        return ans;
    }
};