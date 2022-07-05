class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        int n=nums.size();
        for(int i : nums)
            s.insert(i);
        
        int longest=0;
        
        for(auto element :s)
        {
            int parent = element-1;
            if(s.find(parent)==s.end())
            {
                //head found
                int x = element+1;
                int cnt=1;
                while(s.find(x)!=s.end())
                {
                    x++;
                    cnt++;
                }
                
                longest=max(longest,cnt);
            }
        }
    
      
        return longest;
        
        
        
    }
};