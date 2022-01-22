class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        for(int i=0 ;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int front = i+1;
            int back = nums.size()-1;
            
            while(front<back)
            {
                int s = nums[i]+nums[front]+nums[back];
                
                if(s>0) back--;
                else if(s<0) front++;
                else{
                    res.push_back(vector<int> {nums[i],nums[front],nums[back]});
                    
                    while(front<back && nums[front]==nums[front+1]) front++;
                    while(front<back && nums[back]==nums[back-1]) back--;
                    front++;
                    back--;
                }
                
            }
        }
        return res;
    }
};