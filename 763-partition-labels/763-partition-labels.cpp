class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int> last;
        vector<int> ans;
        int n = s.length();
        if(n==0)
            return ans;
        for(int i=0;i<n;i++)
        {
            last[s[i]]=i;
        }
        
        int i=0,j=0;
        
        int maxL=INT_MIN;
        
        // for(auto it : last)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        while(j<n)
        {
            maxL = max(maxL,last[s[j]]);
            if(j==maxL)
            {
                ans.push_back(j-i+1);
                j++;
                i=j;
            }
            else
            {
                
                if(maxL==n-1)
                {
                    ans.push_back(n-1-i+1);
                    break;
                }
                j++;
            }
            
        }
        return ans;
    }
};