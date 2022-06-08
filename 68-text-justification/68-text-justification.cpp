class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> ans;
        
        int n = words.size();
        int i=0,j=0;
        
        while(i<n)
        {
            
            int wc = words[i].length();
            j=i+1;
            int can=0;
            while(j<n && wc+can+1+words[j].length()<=maxWidth)
            {
                can++;
                wc+=words[j].length();
                j++;
            }
            
            int vac = maxWidth-wc;
            
            int atleast = can==0 ? 0:vac/can;
            int extra = can==0 ? 0 : vac%can;
            
            if(j==n)
            {
                atleast=1;
                extra=0;
            }

            string res="";
            for(int k=i;k<j;k++)
            {
                res+=words[k];
                if(k==j-1) break;
                
                for(int p=0;p<atleast;p++)
                {
                    res+=' ';
                }
                
                if(extra>0)
                {
                    res+=' ';
                    extra--;
                }
                
            }
            
            while(res.length()<maxWidth)
                res+=' ';
            i=j;
            ans.push_back(res);
            
            
        }
        return ans;
    }
};