class Solution {
public:
    int numDecodings(string s) {
        
        int n=s.size();
        
        if(s[0]=='0')
            return 0;
        if(n==1)
            return 1;
        vector<int> t(n+1);
        t[0]=1;
        t[1]=1;
        //226
        for(int i=2;i<=n;i++)
        {
            int way1,way2;
            
            if(s[i-1]=='0') //cant combine if prev digit is 0
                way1=0;
            else
                way1=t[i-1];
            
            string temp=s.substr(i-2,2);
            if(stoi(temp)<=26 && stoi(temp)>0 && s[i-2]!='0')
                way2=t[i-2];
            else
                way2=0;
            
            t[i]=way1+way2;
            
        }
        return t[n];
                
        
    }
};