class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        
        for(char ch : s)
        {
            if(ch==' ')
            {
                if(temp=="")
                {
                    continue;
                }
                else{
                    if(ans=="")
                    {
                        ans=temp;
                    }
                    else
                    {
                    ans=temp+' '+ans;
                    }
                    temp="";
                }
            }
            else{
                temp+=ch;
            }
        }
        if(temp!="")
        {   
            if(ans=="")
            {
                ans=temp;
            }
            else
            {
            ans=temp+' '+ans;
            }
        }
        return ans;
        
    }
};