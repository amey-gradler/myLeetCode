class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        
        int nl = to_string(low).length();
        int nh = to_string(high).length();
        vector<int> ans;
        for(int i=nl;i<=nh;i++)
        {
            
            for(int j=0;j<10-i;j++)
            {
                int x = stoi(s.substr(j,i));
                if(x>=low && x<=high) ans.push_back(x);
            }

        }
        
        return ans;        
        
    }
};