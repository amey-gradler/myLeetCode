class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        
        if(nums.size()==0)
            return res;
        
        if(nums.size()==1)
        {
            res.push_back(nums[0]*nums[0]);
            return res;
        }
        int j=nums.size()-1;
        while(j>0 && nums[j-1]>=0) j--;
        int i=j-1;
        
        while(i>=0 && j<nums.size())
        {
        if(abs(nums[i])>abs(nums[j]))
        {
            res.push_back(nums[j]*nums[j]);
            j++;
        }
        else
        {
            res.push_back(nums[i]*nums[i]);
            i--;
        }
        }
        
        while(i>=0)
        {
            res.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<nums.size())
        {
            res.push_back(nums[j]*nums[j]);
            j++;
        }
        
        return res;
    }
};