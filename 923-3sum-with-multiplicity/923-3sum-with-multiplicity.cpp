class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int mod = 1000000007;
        long long result=0;
        vector<long> cnt(101,0);
        for(int i : arr) cnt[i]++;
        
        for(int i=0;i<=100;i++)
        {
            for(int j=i;j<=100;j++)
            {
                int k = target-i-j;
                if(k<0 || k>100) continue;
                
                if(i==j && j==k)
                {
                    result += ((cnt[i]*(cnt[i]-1)*(cnt[i]-2) )/6)%mod;
                }
                else if(i==j && j!=k)
                {
                    result+= ((cnt[i]*(cnt[i]-1))/2 * cnt[k])%mod;
                }
                else if(i<j && j<k)
                {
                    result+= (cnt[i]*cnt[j]*cnt[k])%mod;
                }
                
            }
        }
        
        return result%mod;
        
    }
};