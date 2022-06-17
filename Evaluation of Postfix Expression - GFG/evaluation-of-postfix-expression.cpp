// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string exp)
    {
        // Your code here
        stack<int> st;
    for(int i=0;i<exp.length();i++)
    {
        char ch = exp[i];
        
        if(ch>='0' && ch<='9')
            st.push(ch-'0');
        else{
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            
            int ans;
            if(ch=='*')
                ans = x*y;
            else if(ch=='/')
                ans = y/x;
            else if(ch=='+')
                ans = x+y;
            else if(ch=='-')
                ans = y-x;
            st.push(ans);
        }    
        
    }
    
    return st.top();
    
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends