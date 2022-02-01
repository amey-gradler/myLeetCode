class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        int isPresent = 0;
        for(auto word : wordList)
        {
            if(word.compare(endWord)==0)
                isPresent = 1;
            set.insert(word);
        }
        
        if(isPresent==0)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            int lsize = q.size();
            while(lsize--)
            {
                string curr = q.front();
                q.pop();
                
                for(int i=0;i<curr.length();i++)
                {
                    string temp = curr;
                    for(char c='a' ; c<='z';c++)
                    {
                        temp[i]=c;
                        if(temp.compare(curr)==0)
                        {
                            //skip the same word
                            continue;
                        }
                        if(temp.compare(endWord)==0)
                        {
                            return depth+1;
                        }
                        if(set.find(temp)!=set.end())
                        {
                            q.push(temp);
                            set.erase(temp);
                        }
                        
                    }
                    
                    
                }
                
            }
        }
        
        return 0;
        
        
        
    }
};