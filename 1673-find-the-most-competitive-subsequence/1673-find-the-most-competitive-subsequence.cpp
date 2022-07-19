class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        stack<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()>nums[i] && st.size()+nums.size()-i>k)
                st.pop();
            if(st.size()<k)
                st.push(nums[i]);
        }
        
        vector<int> ans(k);
        int i=k-1;
        while(!st.empty())
        {
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
        
    }
};