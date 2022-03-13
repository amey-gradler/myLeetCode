class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sumArr=0;
        int n=nums.size();
        for(auto i : nums){
            sumArr+=i;
        }
        
        if(abs(target) > sumArr or (sumArr+target)%2 != 0){
            return 0;
        }
        
        
        
        
        int s1 = (sumArr+target)/2;
        
        //count subsets with sum s1;
        
        //count 0's;
        int c=0;
        for(int i : nums)
            if(i==0) c++;
        
        //initialize
        int t[n+1][s1+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<s1+1;j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
        
        //works
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s1+1;j++){
                
                if(nums[i-1]==0)
                {
                    t[i][j] = t[i-1][j];
                }
                else if(nums[i-1]<=j){
                    
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
                
            }
        }
        
        int x = 1<<c;
        return x*t[n][s1];
        
        
    }
};