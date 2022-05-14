class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        
        if(k==1)
            return max(cardPoints[0],cardPoints[n-1]);
        
        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        if(k==n)
            return total;
        
        vector<int> ps(n+1);
        ps[0]=0;
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=cardPoints[i];
            ps[i+1]=s;
        }
        
        int i=0,j=n-k-1;
        int mini = INT_MAX;
        while(j<n)
        {
            int currentS = ps[j+1]-ps[i];
            mini = min(mini,currentS);
            i++;
            j++;
        }
        
        return total-mini;
        
        
        
    }
};