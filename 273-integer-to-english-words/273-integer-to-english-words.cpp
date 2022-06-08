class Solution {
public:
    
    string ones(int num)
    {
        switch(num)
        {
            case 1 : return "One";
            case 2 : return "Two";
            case 3 : return "Three";
            case 4 : return "Four" ;
            case 5 : return "Five";
            case 6 : return "Six";
            case 7 : return "Seven";
            case 8 : return "Eight";
            case 9 : return "Nine";
        }
        return "";
        
    }
    
    
     string underTwenty(int num)
    {
        switch(num)
        {
            case 10 : return "Ten";
            case 11 : return "Eleven";
            case 12 : return "Twelve";
            case 13 : return "Thirteen";
            case 14 : return "Fourteen" ;
            case 15 : return "Fifteen";
            case 16 : return "Sixteen";
            case 17 : return "Seventeen";
            case 18 : return "Eighteen";
            case 19 : return "Nineteen";
        }
        return "";
        
    }
    
      string tens(int num)
    {
        switch(num)
        {
            case 20 : return "Twenty";
            case 30 : return "Thirty";
            case 40 : return "Forty";
            case 50 : return "Fifty";
            case 60 : return "Sixty" ;
            case 70 : return "Seventy";
            case 80 : return "Eighty";
            case 90 : return "Ninety";
        }
        return "";
        
    }
    
    string twoDigits(int nums)
    {
        if(nums<10)
            return ones(nums);
        if(nums<20)
            return underTwenty(nums);
        
        int tensNum = (nums/10)*10;
        int onesNum = nums%10;
        
        if(onesNum==0)
            return tens(tensNum);
        return tens(tensNum) + " " + ones(onesNum);
        
    }
    
    string threeDigits(int num)
    {
        int hundredsNum = num/100;
        int rest = num%100;
        
        if(hundredsNum == 0)
            return twoDigits(rest);
        
        if(rest==0)
            return ones(hundredsNum) + " " + "Hundred";
        
        return ones(hundredsNum) + " " + "Hundred " + twoDigits(rest); 
        
    }
    
    
    string numberToWords(int num) {
        
        if(num==0) return "Zero";
        
        int billion = num/1000000000;
        num -= (billion*1000000000);
        int million = num/1000000;
        num -= (million*1000000);
        int thousand = num/1000;
        num -= (thousand*1000);
        
        string res;
        if(billion>0)
            res += (threeDigits(billion) + " Billion ");
        
        if(million>0)
            res+= (threeDigits(million) + " Million ");
        
        if(thousand>0)
            res+= (threeDigits(thousand) + " Thousand ");
        
        if(num>0)
            res+=threeDigits(num);
        
        int i=res.length()-1;
        if(res[i]==' ')
            return res.substr(0,i);
    
            
        return res;
        
        
        
    }
};