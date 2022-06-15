class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high)
        {
            mid = low+(high-low)/2;
            cout<<mid;
            if(mid==0)
            {
                low=mid+1;
            }
            else if(mid==n-1)
            {
                high=mid-1;
            }
            else if(mid>0 && mid<n-1)
            {
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                    return mid;
                else if(arr[mid+1]>arr[mid])
            {
                low=mid+1;
            }
                 else{
                high=mid-1;
            }
            }
            
           
            
        }
        return low;
    }
};