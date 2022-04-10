class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int> v;
        int k=0;
        int n = ops.size();
        for(int i=0;i<n;i++)
        {
            if(ops[i]=="+")
            {
                int x = v[k-1]+v[k-2];
                v.push_back(x);
                k++;
            }
            else if(ops[i]=="D")
            {
                v.push_back(v[k-1]*2);
                k++;
            }
            else if(ops[i]=="C")
            {
                v.pop_back();
                k--;
            }
            else{
                v.push_back(stoi(ops[i]));
                k++;
            }
        }
        
        return accumulate(v.begin(),v.end(),0);
        
        
    }
};