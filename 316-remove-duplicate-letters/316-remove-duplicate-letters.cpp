class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> v(26,0);
        vector<int> visited(26,0);
        int n = s.length();
        for(int i=0 ; i< n;i++ )
        {
            v[s[i]-'a']++;
        }
        
        stack<char> st;
        
        for(int i = 0 ; i<n ;i++)
        {
            if( visited[ s[i] - 'a'] )
            {
                v[s[i]-'a']--;
                continue;

            }
                            
            if(!st.empty())
            {
               // char ch  = st.top();
                while( !st.empty() && s[i]<st.top() && v[st.top()-'a']>0)
                {
                    visited[st.top()-'a'] = 0;
                    // v[st.top() - 'a'] ++;
                    st.pop();
                }
                st.push(s[i]);
            }
            else{
                st.push(s[i]);
            }
            visited[ s[i] - 'a'] = 1;
            v[s[i]-'a']--;
        }
        
        string s2 = "";
        while(!st.empty())
        {
            s2 = st.top() + s2;
            st.pop();
        }
        return s2;
        
    }
};