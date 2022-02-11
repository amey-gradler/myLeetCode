class Solution {
public:
    
    void perm(int ind,vector<int> &nums, vector<vector<int>> &ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=ind;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end()) continue;
            s.insert(nums[i]);
            swap(nums[ind],nums[i]);
            perm(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
        
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(0,nums,ans);
        
        return ans;
    }
};