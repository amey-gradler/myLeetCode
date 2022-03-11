class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int n = arr.size();
        
        int mpist=0;
        int leastsf=arr[0];
        vector<int> dpmpisut (n);
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]<leastsf)
            {
                leastsf = arr[i];
            }
            
            mpist = arr[i]-leastsf;
            
            if(mpist>dpmpisut[i-1])
            {
                dpmpisut[i]=mpist;
            }
            else
            {
                dpmpisut[i]=dpmpisut[i-1];
            }
            
        }
        
        int mpibt = 0;
        int maxat = arr[n-1];
        vector<int> dpmpibat(n);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>maxat)
            {
                maxat=arr[i];
            }
            
            mpibt = maxat-arr[i];
            
            if(mpibt > dpmpibat[i+1])
            {
                dpmpibat[i]=mpibt;
            }
            else{
                dpmpibat[i] = dpmpibat[i+1];
            }
            
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans, dpmpisut[i]+dpmpibat[i]);
        }
        return ans;
        
    }
};