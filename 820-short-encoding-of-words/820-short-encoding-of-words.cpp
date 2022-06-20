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
        int cnt=0;
        for(int i=0;i<n;i++)
        {
          // size_t found = prev.find(words[i]);
          //  if(found!=string::npos)
          //  {    
          //      long long int j=found+words[i].length();
          //      // cout<<j<<" "<<prev<<endl;
          //      if(prev[j]=='#')
          //          continue;
          //      else{
          //          prev+=words[i]+'#';
          //      }
          //  }
          //   else{
          //       prev+=words[i]+'#';
          //   }
            
            int begin=0;
            while(begin<prev.length())
            {
                size_t found = prev.find(words[i],begin);
                if(found!=string::npos)
               {    
                   long long int j=found+words[i].length();
                   cout<<j<<" "<<prev<<endl;
                   if(prev[j]=='#')
                       break;
                    else
                        begin=found+1;
               }
                else{
                    prev+=words[i]+'#';
                    break;
                }
            }
            
            if(begin>=prev.length())
                 prev+=words[i]+'#';
            
            
        }
        
        return prev.length();
        
    }
};