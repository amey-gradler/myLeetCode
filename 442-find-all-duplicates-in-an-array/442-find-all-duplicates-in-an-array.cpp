class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        set<int> s;
        for(int i :  nums)
        {
            if(s.find(i)!=s.end())
            {
                ans.push_back(i);
            }
            else
                s.insert(i);
        }
        return ans;
    }
};