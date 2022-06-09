class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int summ = accumulate(nums.begin(),nums.end(),0);
        
        //Lets say at the end after m moves all numbers = x;
        // sum + m*(n-1) = x*n 
        
        //minimum number will always get incremented --> Think of it
        // x = minimum + m;
        // m = sum - (n*minimum);
        
        int m = summ-(n*mini);
        
        return m;
        
        //other method
//         Adding 1s to n - 1 elements effectively is equivalent to subtracting 1 from 1 element. Therefore the question is transformed to: you are allowed to remove 1 from 1 element each steps, and your goal is to make all element equal.


// After the removal, total sum is minNum * n, hence the number of step needed is sum - minNum * n.
    }
};