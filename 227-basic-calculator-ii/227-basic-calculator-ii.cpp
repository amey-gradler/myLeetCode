class Solution {
public:
    
    int precedence(char ch)
    {
        if(ch=='*' || ch=='/')
            return 2;
        if(ch=='+' || ch=='-')
            return 1;
        return 0;
        
    }
    
    string toPostfix(string s)
    {
        stack<char> st;
        string post="";
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
                continue;
            else if(isdigit(s[i]))
            {
                post+=s[i];
            }
            else {
                post+='|';
                while(!st.empty() && precedence(s[i])<= precedence(st.top()))
                {
                    post+=st.top();
                    st.pop();
                }
                
                st.push(s[i]);
                
            }
        }
        
        post+='|';
        while(!st.empty())
        {
            post+=st.top();
            st.pop();
        }
        
        return post;
        
        
    }
    
    int calculate(string s) {
        
        s=toPostfix(s);

        cout<<s<<endl;
        stack<int> num;
        
        for(int i=0;i<s.length();i++)
        {
            
            if(isdigit(s[i]))
            {
                int cur=0;
                while(i<s.length() && isdigit(s[i]))
                {
                    cur= cur*10 + (s[i]-'0');
                    i++;
                    
                }
                num.push(cur);
                
            }
            else{
                int num1 = num.top();
                num.pop();
                int num2 = num.top();
                num.pop();
                cout<<num1<<" "<<num2<<endl;
                
                if(s[i]=='+')
                {
                    num.push(num1+num2);
                }
                else if(s[i]=='-') num.push(num2-num1);
                else if(s[i]=='*') num.push(num1*num2);
                else if(s[i]=='/') num.push(num2/num1);
            }
            

        }
                    return num.top();
    }
};