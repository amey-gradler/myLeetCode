class Solution {
public:
    
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
       
        sort(courses.begin(),courses.end(),cmp);
        // for(auto a : courses)
        // {
        //     cout<<a[0]<<" "<<a[1]<<endl;
        // }
        
        priority_queue<int> pq;
        int totalTime=0;
        
        for(int i=0;i<courses.size();i++)
        {
            if(totalTime+courses[i][0]<=courses[i][1])
            {
                totalTime+=courses[i][0];
                pq.push(courses[i][0]);
            }
            else{
                if(!pq.empty() && pq.top()>courses[i][0])
                {
                    int top = pq.top();
                    pq.pop();
                    totalTime -= top;
                    totalTime += courses[i][0];
                    pq.push(courses[i][0]);
                }
            }
            
        }
        
        
        return pq.size();
    }
};