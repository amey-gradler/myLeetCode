class Solution {
public:
    int parents[1001];
    
    int findPar(int node)
    {
        if(parents[node] == node)
            return node;
        return parents[node] = findPar(parents[node]);
    }
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map <string,int> email_to_id;
        
        for(int i=0;i<accounts.size();i++)
        {
            parents[i]=i;
            
            for(int j=1;j<accounts[i].size();j++)
            {
                if(email_to_id.find(accounts[i][j]) != email_to_id.end())
                {
                    int parent1 = findPar(i);
                    int parent2 = findPar(email_to_id[accounts[i][j]]);
                    
                    parents[parent1] = parent2;
                    
                }
                else
                {
                    email_to_id[accounts[i][j]] = parents[i];
                }
            }
        }
        
         unordered_map<int, vector<string>> resultant_map;
            
            for(auto it: email_to_id)
            {
                int uniq_id = findPar(it.second); 
                resultant_map[uniq_id].push_back(it.first);
            }
            
            // uff tired, so now towards final ans
            vector<vector<string>> ans;
            for(auto it: resultant_map)
            {
                vector<string> email = it.second;
                
                // question demand in sorted order
                sort(email.begin(), email.end());
                
                // inserting name in starting with the help of unique id
                email.insert(email.begin(), accounts[it.first][0]);
                
                ans.push_back(email);
            }
        return ans;
        
    }
};