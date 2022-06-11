// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isValid(int A[],int N,int M,int maxi)
    {
        int Students=1;
        int sum=0;
        
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum>maxi)
            {
                Students++;
                sum=A[i];
            }
        }
        
        if(Students>M) return false;
        return true;
    }
    
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)
            return -1;
        
        int low=*max_element(A,A+N);
        int high = accumulate(A,A+N,0);
        int res;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(isValid(A,N,M,mid))
            {
                res = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return res;
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends