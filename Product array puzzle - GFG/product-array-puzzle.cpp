// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> res(n);
        if(n==1)
        {
            res[0]=1;
            return res;
        }
        vector<int> ZeroInd;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                ZeroInd.push_back(i);
        }
        
        if(ZeroInd.size()>1)
        {
             vector<long long int> res2(n,0);
             return res2;
        }
        else if(ZeroInd.size()==1)
        {
             vector<long long int> res2(n,0);
             long long int prod=1;
             
             for(int i=0;i<n;i++)
             {
                if(nums[i]==0)
                    continue;
                prod = prod*nums[i];
             }
             
             res2[ZeroInd[0]] = prod;
             return res2;
             
        }
        else{
            
            vector<long long int> pre(n);
            vector<long long int> suf(n);
             vector<long long int> prod(n);
            pre[0]=1;
            suf[n-1]=1;
            for(int i=1;i<n;i++)
            {
                pre[i] = pre[i-1]*nums[i-1];
            }
            
            for(int j = n-2;j>=0;j--)
            {
                suf[j] = suf[j+1] *nums[j+1]; 
            }
            
            for(int i=0;i<n;i++)
            {
                prod[i] = pre[i]*suf[i];
            }
            
            return prod;
            
        }
        
        
        return res;
        
        
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends