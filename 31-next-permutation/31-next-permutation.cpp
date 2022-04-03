class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        //start from right side and find a no < its next no
        int i=n-1;
        while(i>0){
            if(nums[i]>nums[i-1]){
                break;
            }
            i--;
        }
        
        
         if(i==0){
            sort(nums.begin(), nums.end());
            return ;
        }
        
        int x = nums[i-1],smallest = nums[i];
        int smallestPos = i;
        for(int j = i+1;j<n;j++){
            if(nums[j]<smallest && nums[j]>x){
                smallest = nums[j];
                smallestPos=j;
            }
        }
        
        int temp=0;
        temp =nums[i-1];
        nums[i-1] = nums[smallestPos];
        nums[smallestPos]= temp;
        
        sort(nums.begin()+i,nums.end());   
        
    }
};                                                                                                                                                                                                                                                                                                                                                                                                                  
