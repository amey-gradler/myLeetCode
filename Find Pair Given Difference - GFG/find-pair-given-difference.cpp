// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    
    
   int i=0;
   int j=1;
   
   while(i<size && j<size)
   {
       if(i!=j && abs(arr[i]-arr[j])==n )
            return true;
        else if(arr[j]-arr[i]<n)
            j++;
        else
            i++;
   }
    
    return false;
    
}

// int binSearch(int arr[],int x,int size)
// {
//     int low=0;
//     int high = size-1;
    
//     while(low<=high)
//     {
//         int mid = low + (high-low)/2;
        
//         if(arr[mid]==x)
//             return mid;
//         else if(arr[mid]<x)
//         {
//             low=mid+1;
//         }
//         else
//         {
//             high=mid-1;
//         }
//     }
    
//     return -1;
// }
