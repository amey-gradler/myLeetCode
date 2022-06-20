class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n=s.length();
        stack<pair<char,int>> st;
        
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(st.empty())
            {
                st.push({ch,1});
            }
            else{
                
                if(st.top().first==ch)
                {
                    int cnt = st.top().second+1;
                    if(cnt==k)
                        st.pop();
                    else{
                        st.pop();
                        st.push({ch,cnt});
                    }
                    
                }
                else{
                    st.push({ch,1});
                }
                
            }
        }
        
        string res="";
        while(!st.empty())
        {
            char ch = st.top().first;
            int cnt = st.top().second;
            st.pop();
            while(cnt--)
                res+=ch;
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};