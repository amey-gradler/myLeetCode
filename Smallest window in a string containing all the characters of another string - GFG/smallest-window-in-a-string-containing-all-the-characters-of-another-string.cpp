// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int j=0;
        int i=0;
        int startI=0;
        int mini = INT_MAX;
        
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<p.length();i++)
        {
            mp[p[i]]++;
        }
        int count = mp.size();
        
        
        while(j<s.length())
        {
            
            if(mp.find(s[j])!=mp.end() )
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
                
            }
            
            if(count==0)
            {
                
                while(count==0)
                {
                    if(j-i+1<mini)
                    {
                        mini=j-i+1;
                        startI=i;
                    }
                    
                    if(mp.find(s[i])!=mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                            count++;
                    }
                    i++;
                    
                }
            
            }
            j++;
            
            
        }
        
        
        string st = s.substr(startI,mini); 
        if(mini==INT_MAX)
            return "-1";
        return st;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends