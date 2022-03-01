class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return 0;
        
        int longest=0;
        for(int i=1;i<n-1;i++)
        {
            
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                //peak found
                int left=i-1,right=i+1;
                while(left>=0 && arr[left]<arr[left+1])
                    left--;
                left++;
                while(right<n && arr[right]<arr[right-1])
                    right++;
                right--;
                int length = (i-left) + (right-i)+1;
                longest=max(longest,length);
                
            }
        }
        return longest;
        
    }
    
};