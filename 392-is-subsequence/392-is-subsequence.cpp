class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int ns=s.length();
        int nt = t.length();
        
        if(ns>nt)
            return false;
        
        int i=0;
        int j=0;
        while(i<ns && j<nt){
            if(s[i]==t[j])
            {
                i++;
                j++;
            }else{
                j++;
            }
        }
        
        if(i>=ns)
            return true;
        return false;
        
        
    }
};