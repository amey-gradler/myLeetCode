class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string res="";
        int n = columnNumber;
        while(n>26)
        {
            int x = n%26;
            if(x==0)
            {
                x=26;
                n-=26;
            }
            res+= ('A'+x-1);
            n=n/26;
        }
        
        res+= ('A'+n-1);
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};