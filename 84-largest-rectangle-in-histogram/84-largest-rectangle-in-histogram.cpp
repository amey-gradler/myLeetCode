class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> leftSmall;
        vector<int> rightSmall(n);
        
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                leftSmall.push_back(0);
            }
            else{
                leftSmall.push_back(st.top()+1);
            }
            
            st.push(i);
            
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        
        for(int i=n-1;i>=0;i--)
        {
            
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                rightSmall[i]=(n-1);
            }
            else{
                rightSmall[i]=(st.top()-1);
            }
            
            st.push(i);
            
        }
  
        
        
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, (rightSmall[i]-leftSmall[i]+1)*heights[i] );
        }
        
        return maxi;
        
        
        
    }
};