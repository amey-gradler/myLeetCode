class Solution {
public:
    int findComplement(int num) {
        
        int ans=1,n=num;
        
        while(n!=1){
            n>>=1;
            ans<<=1;
            ans |=1;
        }
        
        ans=ans^num;
        return ans;
        
    }
};