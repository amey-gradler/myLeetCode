class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int n=s.length();
        int start=0;
        int end = n-1;
        
        while(start<=end)
        {
            if(!isalpha(s[start]))
            {
                start++;
                continue;
            }
            
            if(!isalpha(s[end]))
            {
                end--;
                continue;
            }
            
            swap(s[start],s[end]);
            start++;
            end--;
        }
        
        return s;
    }
};