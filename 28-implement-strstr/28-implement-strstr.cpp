class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = needle.length();
        int m = haystack.length();
        if(n==0)
            return 0;
        
        vector<int> lps = kmp(needle);
        
        for(int i=0,j=0;i<m;)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            
            if(j==n)
                return i-j;
            if(i<m && haystack[i]!=needle[j])
            {
                if(j>0)
                {
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
            
        }
        return -1;
        
        
    }
    
    vector<int> kmp(string needle)
    {
        int n = needle.length();
        vector<int> lps(n,0);
        
        for(int i=1,len=0;i<n;)
        {
            
            if(needle[i]==needle[len])
            {
                lps[i++] = ++len;
            }
            else if(len)
            {
                len = lps[len-1];
            }
            else{
                lps[i++]=0;
            }
            
        }
        return lps;       
    }
    
};