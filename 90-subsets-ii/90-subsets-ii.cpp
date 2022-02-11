class Solution {
public:
    
      void findC(int ind,vector<int> &arr, vector<int> &res,vector<vector<int>> &ans )
    {
        
        ans.push_back(res);
            
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1]) continue;
            
            res.push_back(arr[i]);
            findC(i+1,arr,res,ans);
            res.pop_back();
        }
        
    }
    
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        
        findC(0,nums,res,ans);
        return ans;
        
    }
};