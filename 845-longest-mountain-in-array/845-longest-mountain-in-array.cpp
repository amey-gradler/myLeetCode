class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return 0;
        
        int longest=0;
        for(int i=1;i<n-1;)
        {
            
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                //peak found
                int cnt=1;
                int j=i;
                
                while(j>=1 && arr[j-1]<arr[j])
                {
                    j--;
                    cnt++;
                }
                
                while(i<n-1 && arr[i+1]<arr[i])
                {
                    cnt++;
                    i++;
                }
                longest = max(longest,cnt);
                
            }
            else{
                i++;
            }
        }
        return longest;
        
    }
    
};