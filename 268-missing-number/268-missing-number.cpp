class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size()+1;
        
        int sumAll = n*(n+1);
        sumAll/=2;
        sumAll -=n;
        int sumArr = accumulate(nums.begin(),nums.end(),0);
        return sumAll - sumArr;
        
    }
};