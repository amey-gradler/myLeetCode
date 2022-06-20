class Solution {
public:
    
    static bool cmp(string& a,string &b)
    {
        if(a.length()==b.length())
            return b>a;
        else
            return b.length()<a.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        int n = words.size();
        if(n==1)
            return words[0].length()+1;
        
        sort(words.begin(),words.end(),cmp);
        
//         for(string s : words)
//             cout<<s<<" ";
//         cout<<endl;
        
        string prev="";
        for(int i=0;i<n;i++)
        {
          
            int found = prev.find(words[i]+'#');
            if(found!=-1)
                continue;
            else
                prev+=words[i]+'#';
        }
        
        return prev.length();
        
    }
};