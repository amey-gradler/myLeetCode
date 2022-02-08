class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        
        int x = (tomatoSlices-2*cheeseSlices);
        if(x<0 || x%2!=0)
            return {};
        x=x/2;
        int y=cheeseSlices-x;
        if(y<0)
            return {};
        
        return {x,y};
        
    }
};