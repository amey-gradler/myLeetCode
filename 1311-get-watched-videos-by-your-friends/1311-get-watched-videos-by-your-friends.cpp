class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
     // friend == adjList 
        int n = friends.size();
        vector<int> visited(n,0);
        
        unordered_map<string,int> mp;
        vector<pair<int,string>> resultPairs;
        vector<string> result;
        queue<int> q;
        visited[id] = 1;
        q.push(id);
        while(!q.empty() && level--)
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                for(auto it : friends[node])
                {
                    if(!visited[it])
                    {
                        visited[it]=1;
                        q.push(it);
                    }
                }
                
            }
        }
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(auto it :  watchedVideos[x])
            {
                mp[it]++;
            }
        }
        
        for(auto it = mp.begin(); it!=mp.end();it++)
        {
            resultPairs.push_back({it->second,it->first});
        }
        sort(resultPairs.begin(),resultPairs.end());
         transform(resultPairs.begin(),resultPairs.end(),back_inserter(result),[](pair<int,string>&p){return p.second;}); //Transform the pairs to result
        return result;
    }
};