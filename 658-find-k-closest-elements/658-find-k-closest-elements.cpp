class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        priority_queue<pair<int,int>> maxH;
        
        for(int i=0;i<arr.size();i++)
        {
            maxH.push({ abs(arr[i]-x) , arr[i]});
            
            if(maxH.size()>k)
            {
                maxH.pop();
            }
            
        }
        
        while(maxH.size())
        {
            int j = maxH.top().second;
            maxH.pop();
            // ans.insert(ans.begin(),j);
            ans.push_back(j);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};