class Solution {
public:
    int nextGreaterElement(int n) {
        
        string s = to_string(n);
        if(next_permutation(s)) 
        {
            long long res = stoll(s);
            if(res>INT_MAX || res<=n) 
                return -1;
            return res;
        }
        return -1;
    }
    
    bool next_permutation(string &nums)
    {
        if(nums=="") return false;
        int n= nums.length();
        int i= n-1;
        
        while(i>0 && nums[i]<=nums[i-1]) i--;
        if(i==0) return false;
        
        int x = nums[i-1] ;
        int smallest=i;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]>x && nums[j]<nums[smallest])
                smallest =j;
        }
        
        char temp=nums[i-1];
        nums[i-1]=nums[smallest];
        nums[smallest] = temp;
        
        sort(nums.begin()+i,nums.end());
        return true;
        
    }
    
    
};