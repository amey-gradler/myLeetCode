class Solution {
public:
    
    bool isSubseq(string s1,string s)
    {
        int m=s1.length();
        int n = s.length();        
        
        if(m>n) return false;
        
        int i=m-1;
        int j=n-1;
        
        while(i>=0 && j>=0)
        {
            if(s1[i]==s[j])
            {
                i--;
                j--;
            }
            else
            {
                j--;
            }
        }
        
        
        return i<0;
        
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto i : words)
        {
            mp[i]++;
        }
        
        int sum=0;
        for(auto it : mp)
        {
            if(isSubseq(it.first,s))
                sum+=it.second;     
        }
        
        return sum;
    }
};