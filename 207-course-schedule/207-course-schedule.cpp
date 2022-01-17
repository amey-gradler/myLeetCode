class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    int n = numCourses;
    vector<int> adjList[n];
	
	for(int i=0;i<prerequisites.size();i++)
	{	
		adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
	}
	
	queue<int> q;
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++)
	{
		for(auto it : adjList[i])
			indegree[it]++;
	}
	
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	
	int cnt=0;
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cnt++;
		// cout<<node<<" ";
		for(auto it : adjList[node])
		{
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
	}
	
	//not cyclic course possible
	if (cnt==n)
		return true;
	return false;
    }
};