class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n=pushed.size();
        vector<int> inStack(n,0);
        stack<pair<int,int>> st;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[pushed[i]]=i;
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && inStack[mp[popped[i]]] != 0)
            {
                if(st.top().first != popped[i])
                {
                    cout<<popped[i];
                    return false;            
                }else{
                    st.pop();
                }
            }
            else if(inStack[mp[popped[i]]] == 0)
            {
                
                int k=0;
                if(!st.empty())
                {
                    k=st.top().second + 1;
                }
                
                while(k<n && k<mp[popped[i]])
                {
                    if(inStack[k]==0)
                    {
                        st.push({pushed[k],k});
                        inStack[k]=1;
                    }
                    k++;
                }
                
                inStack[k]=1;
                
            }
        }
        
        return true;
        
    }
};