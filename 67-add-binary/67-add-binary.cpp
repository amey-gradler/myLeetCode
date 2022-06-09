class Solution {
public:
    string addBinary(string a, string b) {
        
        string res="";
        int i=a.length()-1;
        int j = b.length()-1;
        int c=0;
        
        while(i>=0 && j>=0)
        {
            if(a[i]=='0' && b[j]=='0')
            {
                if(c==1)
                {
                    res+='1';
                    c=0;
                }
                else{
                    res+='0';
                }
            }
            
            else if( (a[i]=='1' && b[j]=='0') || (a[i]=='0' && b[j]=='1') )
            {
                if(c==1)
                {
                    res+='0';
                    c=1;
                }
                else{
                    res+='1';
                }
            }
            else if(a[i]=='1' && b[j]=='1')
            {
                if(c==1)
                {
                    res+='1';
                    c=1;
                }
                else{
                    res+='0';
                    c=1;
                }
            }
            
            i--;
            j--;
            
        }
        
        while(i>=0)
        {
            if(a[i]=='0')
            {
                if(c==1)
                {
                    res+='1';
                    c=0;
                }
                else{
                    res+='0';
                }
            }
            else if(a[i]=='1')
            {
                if(c==1)
                {
                    res+='0';
                    c=1;
                }
                else{
                    res+='1';
                }
            }
            i--;
        }
        
          while(j>=0)
        {
            if(b[j]=='0')
            {
                if(c==1)
                {
                    res+='1';
                    c=0;
                }
                else{
                    res+='0';
                }
            }
            else if(b[j]=='1')
            {
                if(c==1)
                {
                    res+='0';
                    c=1;
                }
                else{
                    res+='1';
                }
            }
            j--;
        }
        
        if(c>0)
            res+='1';
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};