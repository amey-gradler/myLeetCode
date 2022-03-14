class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.size();
        stack<string> s;
        for(int i=0;i<n;i++)
        {
            
            if(path[i]=='/')
                continue;
            string temp="";
            while(i<n && path[i]!='/')
            {
                temp+=path[i];
                i++;
            }
            if(temp==".")
                continue;
            if(temp=="..")
            {
                if(!s.empty())
                    s.pop();
                continue;
            }
            s.push(temp);
        }
        
        
        string ans="";
        while(!s.empty())
        {
            ans = '/'+s.top()+ans;
            s.pop();
        }
        if(ans=="")
            return "/";
        return ans;
        
        
    }
};