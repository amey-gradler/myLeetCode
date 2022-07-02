class Solution {
public:
    long long mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
     
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        
        int maxH=hC[0],maxV=vC[0];
        int n = hC.size();
        for(int i=1;i<n;i++)
        {
            maxH=max(maxH,hC[i]-hC[i-1]);
        }
        
        maxH = max(maxH,h-hC[n-1]);
        // if(n==1)
            // maxH=hC[n-1];
        n = vC.size();
        
        for(int i=1;i<n;i++)
        {
            maxV = max(maxV,vC[i]-vC[i-1]);
        }
        
        maxV = max(maxV,w-vC[n-1]);
        // if(n==1)
            // maxV=vC[n-1];
        return (maxH%mod * maxV%mod)%mod;
        
    }
};