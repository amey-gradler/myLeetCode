class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        unordered_set<string> visited;
        vector<vector<string>> ans;
        
        int isPresent = 0;
        for(auto word : wordList)
        {
            if(word.compare(endWord)==0)
                isPresent=1;
            set.insert(word);
        }
        
        if(isPresent==0)
            return ans;
        
        queue<vector<string>> q;
        q.push({beginWord});

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto curr_path = q.front();
                q.pop();
                string curr_string = curr_path.back();
                for(int i=0;i<curr_string.length() ; i++)
                {
                    string temp=curr_string;
                    for(char c = 'a' ; c<='z';c++)
                    {
                        temp[i]=c;
                        
                        if(set.find(temp)!=set.end())
                        {
                            auto new_path = curr_path;
                            new_path.push_back(temp);
                            visited.insert(temp);
                            if(temp==endWord)
                            {
                                ans.push_back(new_path);
                            }
                            else{
                                q.push(new_path);
                            }
                                
                        }
                    }
                    
                }
            }
            for(auto& str : visited)
                    set.erase(str);
        }
        return ans;
    }
};