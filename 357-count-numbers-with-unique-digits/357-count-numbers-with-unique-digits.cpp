class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        //n=1 -> 10 
        //n=2 -> 10 + (9*9) = 91
        //n=3 -> 10 + 81 + (9*9*8) = 
        //n=4 -> 10+81+(9*9*8) + (9*9*8*7)
        //(9-k+2)
        vector<int> t(n+1,0);
        t[0]=1;
        t[1]=10;
        t[2]=91;
        for(int i=3;i<=n;i++)
        {
            t[i] = t[i-1] + (t[i-1]-t[i-2])*(9-i+2);
        }
        return t[n];
        
        
    }
};