class Solution {
public:
    char parent[26];
    
    char find(char ch)
    {
        if(parent[ch]==ch)
            return ch;
        return parent[ch] = find(parent[ch]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        int n=equations.size();
        
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='=')
            {
                int x = find(equations[i][0]-'a');
                int y = find(equations[i][3]-'a');
                if(x!=y)
                {
                    parent[y]=x;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!')
            {
                int x = find(equations[i][0]-'a');
                int y = find(equations[i][3]-'a');
                if(x==y)
                {
                    return false;
                }
            }
        }
        return true;
        
        
    }
};