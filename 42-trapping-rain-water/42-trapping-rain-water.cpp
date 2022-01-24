class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(); 
        vector<int> LH(n,INT_MIN);
        vector<int> RH(n,INT_MIN);
        LH[0]=height[0];
        RH[n-1] = height[n-1];
        for(int i=1,j=n-2;i<n,j>=0;i++,j--)
        {
            LH[i] = max(height[i],LH[i-1]);
            RH[j] = max(height[j],RH[j+1]);
        }
        
        int water=0;
        for(int i=0;i<n;i++)
        {
            water+= min(LH[i],RH[i]) - height[i];
        }
        
        return water;
    }
};