typedef pair<int,int> pi;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        unordered_map<int,int> mp;
        for(int i : nums)
        {
            mp[i]++;
        }
        
        
        priority_queue<pi,vector<pi>, greater<pi>> minH;
        
        for(auto it : mp)
        {
            minH.push({it.second,it.first});
            if(minH.size()>k) minH.pop();
        }
        
        while(minH.size())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        
        return ans;
        
    }
};