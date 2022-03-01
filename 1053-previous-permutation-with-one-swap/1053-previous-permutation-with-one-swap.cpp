class Solution {
public:
    
    bool is_sorted(vector<int> arr)
    {
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>arr[i])
            {
                return false;
            }
        }
        return true;
    }
    
    
    int find(vector<int> arr,int n1)
    {
        int i=n1+2;
        int idx=n1+1;
        while(i<arr.size())
        {
            if(arr[i]<arr[n1] && arr[i]>arr[idx])
            {
                idx=i;
            }
            i++;
        }
        
        return idx;
    }
    
    vector<int> prevPermOpt1(vector<int>& arr) {
        
        int n=arr.size();
        if(n<2 || is_sorted(arr))
        {
            return arr;
        }
        
        int n1=n-2;
        while(n1>=0 && arr[n1]<=arr[n1+1])
        {
            n1--;
        }
        
        int n2 = find(arr,n1);
        
        swap(arr[n1],arr[n2]);
        return arr;        
    }
};