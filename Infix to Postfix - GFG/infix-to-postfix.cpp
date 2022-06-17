// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int prec(char ch)
    {
        if(ch=='^')
            return 3;
        else if(ch=='*' || ch=='/')
            return 2;
        else if(ch=='+' || ch=='-')
            return 1;
        return -1;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        
        string res="";
        
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            
            if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
            {
                res+=ch;
            }
            else if(ch=='(')
                st.push('(');
            else if(ch==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else{
                while(!st.empty() && prec(s[i])<=prec(st.top()) )
                {
                    if(ch=='^' && st.top()=='^')
                        break;
                    else
                    {
                        res+=st.top();
                        st.pop();
                    }
                }
                st.push(ch);
                
            }
            
        }
        
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        
        return res;   
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends