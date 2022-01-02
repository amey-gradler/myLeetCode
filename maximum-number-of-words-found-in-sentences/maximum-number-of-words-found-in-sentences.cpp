class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int maxWords=INT_MIN;
        for(string s : sentences)
        {   
            int spaces=0;
            for (char c:s)
            {
                if(c==' ')
                    spaces++;
            }
            
            maxWords = max(maxWords , spaces+1);
        }
        
        return maxWords;
    }
};