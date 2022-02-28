class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        int n=nums.size();
        if(n==0)
            return ans;
        
        string str=to_string(nums[0]);
        
        int last = nums[0];
        
        for(int i=1;i<n;i++)
        {
        
            if(nums[i]==(last+1))
            {
                // cout<<nums[i];
                last=nums[i];
            }
            else
            {   
                 if(stoi(str)==last)
                {
                    ans.push_back(str);
                }
                else
                {
                    str+="->"+to_string(last);
                    ans.push_back(str);
                }
                str=to_string(nums[i]);
                last=nums[i];
            }
        }
        if(stoi(str)==last)
        {
            ans.push_back(str);
        }
        else
        {
            str+="->"+to_string(last);
                ans.push_back(str);
        }
        
        return ans;
        
    }
};