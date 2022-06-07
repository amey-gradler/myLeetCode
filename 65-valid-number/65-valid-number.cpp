class Solution {
public:
    bool isNumber(string s) {
        
        int n = s.length();
        if(n==1)
        {
            if(s[0]>='0' && s[0]<='9')
                return true;
            return false;
        }
        
        int signCnt=0,eCnt=0,dotCnt=0,digitCnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                digitCnt++;
                continue;
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                if(signCnt==2) return false;
                
                if(i>0 && i!=n-1)
                {
                    if(s[i-1]!='e' && s[i-1]!='E')
                        return false;
                }
                else if(i!=0) return false;
                
                signCnt++;
                
            }
            else if(s[i]=='e' || s[i]=='E')
            {
                if(eCnt!=0) return false;
                if(digitCnt==0) return false;
                if(i==0 || i==n-1) return false;
                eCnt=1;
            }
            else if(s[i]=='.')
            {
                if(dotCnt!=0) return false;
                if(eCnt==1) return false;
                dotCnt=1;
            }
            else{
                return false;
            }
        }
        

        
        if(dotCnt==1 && digitCnt==0)
            return false;
        
        return true;
        
    }
};