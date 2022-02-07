class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        int n = tokens.size()-1;
        
        int s=0;
        int e = n;
        int finalS=0;
        int score=0;
        while(s<=e)
        {
            if(tokens[s]<=power)
            {
                power-=tokens[s];
                s++;
                score++;
            }else
            {   
                if(score==0)
                {
                    return 0;
                }
                power+=tokens[e];
                e--;
                score--;
            }
            finalS = max(score,finalS);
        }
        
        return finalS;
        
        
    }
};