class Solution {
public:
    string removeDuplicates(string s) {
        
        int n = s.length();
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(st.empty())
            {
                st.push(ch);
            }
            else{
                
                if(st.top()==ch)
                {
                    st.pop();
                }
                else{
                    st.push(ch);
                }
                
            }
            
        }
        
        string res="";
        while(!st.empty())
        {
            res = st.top()+res;
            st.pop();
        }
        
        return res;
    }
};