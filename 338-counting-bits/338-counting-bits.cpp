class Solution {
public:
    
    int solve(int n)
    {
        int cnt=0;
        while(n!=0)
        {
            int rsb = n &(-n);
            n=n-rsb;
            cnt++;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
            for(int i=0;i<=n;i++)
            {
                ans.push_back(solve(i));
            }
        return ans;
    }
};