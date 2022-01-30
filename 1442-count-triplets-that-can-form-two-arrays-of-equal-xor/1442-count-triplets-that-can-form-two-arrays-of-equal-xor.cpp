class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {   
            int val = arr[i];
            for(int k=i+1;k<n;k++)
            {
                val = val^ arr[k];
                
                if(val==0)
                {
                    cnt+=(k-i);
                }
                
            }
        }
        
        return cnt;
        
    }
};