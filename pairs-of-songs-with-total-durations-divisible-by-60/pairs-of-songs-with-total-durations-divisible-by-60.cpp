class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
     
        map<int,int> counts;
        
        int total=0;
        
        for(int i : time)
        {
            counts[i%60]++;
        }
        
        if(counts[0]>0)
            total+=(counts[0]*(counts[0]-1))/2;        
   
        if(counts[30]>0)
            total+=(counts[30]*(counts[30]-1))/2;
        
     
        
        for(int i=1;i<30;i++)
        {
            total+=(counts[i]*counts[60-i]);
        }
                    
        return total;
        
    }
};