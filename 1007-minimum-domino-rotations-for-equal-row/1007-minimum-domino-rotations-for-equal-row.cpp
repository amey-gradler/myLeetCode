class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        vector<int> cntT(7),cntB(7),same(7);
        int n = tops.size();
        for(int i=0;i<n;i++)
        {
            cntT[tops[i]]++;
            cntB[bottoms[i]]++;
            
            if(tops[i]==bottoms[i])
                same[tops[i]]++;
        }
        
        for(int i=0;i<7;i++)
        {
            if(cntT[i]+cntB[i]-same[i]==n)
            {
                return n -  max(cntB[i],cntT[i]);
            }
        }
        
        return -1;
        
    }
};