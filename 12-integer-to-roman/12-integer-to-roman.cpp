class Solution {
public:
    string intToRoman(int num) {
        vector<int> values {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        int i=0;
        string str="";
        while(num>0)
        {
            if(values[i]<=num)
            {
                str+=roman[i];
                num=num-values[i];
            }
            else
            {
                i++;
            }
        }
        
        return str;
        
        
    }
};