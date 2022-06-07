class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if(strs.size()==1 && strs[0]=="")
        {
            return {{strs[0]}};
        }
        
        unordered_map <string,vector<string>> ump;
        
        for(auto s: strs)
        {
            string temp =s;
            sort(temp.begin(),temp.end());
            
            ump[temp].push_back(s);
            
        }
        
        vector<vector<string>> ans;
        
        for(auto it = ump.begin(); it!=ump.end() ;it++)
        {
            ans.push_back(it->second);
            
        }
        
        return ans;
        
        
        
    }
};