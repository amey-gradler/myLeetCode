class Solution {
public:
    bool isPalindrome(int x) {
        
        int num = x;
        long long int n=0;
        while(x>0)
        {
            int d = x%10;
            n = n*10+d;
            x/=10;
        }
        
        return num==n;
        
    }
};