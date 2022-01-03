class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> leftmp;
        unordered_map<int,int> rightmp;
        
        for(int i=0;i<trust.size();i++)
        {
            leftmp[trust[i][0]]++;
            rightmp[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(leftmp[i]==0 && rightmp[i]==n-1)
                return i;
        }
        
        return -1;
        
    }
};