class Solution {
public:
    
    int count=0;
    
    
    void solve(int ind,vector<int> & arr,int n)
    {
        if(ind==n)
        {
            count++;
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(arr[i]%(ind+1)==0 || (ind+1)%arr[i]==0)
            {
                swap(arr[i],arr[ind]);
                solve(ind+1,arr,n);
                swap(arr[ind],arr[i]);
            }
            
        }
        return;
        
    }
    
    int countArrangement(int n) {
        
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
        
        solve(0,arr,n);
        return count;  
        
    }
};