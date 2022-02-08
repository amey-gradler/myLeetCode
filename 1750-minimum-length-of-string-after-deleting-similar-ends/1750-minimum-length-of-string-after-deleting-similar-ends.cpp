class Solution {
public:
    int minimumLength(string s) {
        int minL = s.length();
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]==s[j])
            {
                while(s[i]==s[i+1] && i<j) i++;
                while(s[j]==s[j-1] && i<j ) j--;
                
                i++;
                j--;
                
                minL = j-i+1;
                if(minL<=0)
                    return 0;
                
            }
            else
            {
                return minL;
            }
        }
        
        return minL;
    }
};