class Solution {
public:
    bool judgeSquareSum(int c) {
        
        if(c<3)
            return true;
        
        long long int low=0;
        long long int high = sqrt(c);
        
        while(low<=high)
        {
            long long int x = (low*low) + (high*high);
            if(x==c)
                return true;
            else if(x<c)
            {
                low++;
            }
            else{
                high--;
            }
        }
        
        return false;
    }
};