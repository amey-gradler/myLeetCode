class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        version1+='.';
        version2+='.';
        
        int l1=version1.length();
        int l2=version2.length();
        
        int flag=0;
        int i=0,j=0;
        while(i<l1 && j<l2)
        {
            string s1="",s2="";
            while(version1[i]!='.')
            {
                s1+=version1[i];
                i++;   
            }
            
            while(version2[j]!='.')
            {
                s2+=version2[j];
                j++;
            }
            
            
            int n1=stoi(s1);
            int n2=stoi(s2);
            if(n1>n2)
            {
                return 1;
            }
            else if(n2>n1)
            {
                return -1;
            }
            i++;
            j++;
        }
        
        while(i<l1)
        {
             string s1="";
            while(version1[i]!='.')
            {
                s1+=version1[i];
                i++;   
            }
            if(stoi(s1)>0)
                return 1;
            i++;
        }
        
        while(j<l2)
        {
             string s2="";
            while(version2[j]!='.')
            {
                s2+=version2[j];
                j++;   
            }
            if(stoi(s2)>0)
                return -1;
            j++;
        }
        
        return 0;
    }
};