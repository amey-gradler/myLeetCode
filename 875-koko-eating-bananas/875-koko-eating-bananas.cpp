class Solution {
public:
    bool canEat(vector<int> & piles,int h,int k){
        int hours=0;
        int div;
        for(int pile:piles)
        {
            div = pile/k;
            hours+=div;
             if(pile % k != 0) hours++;
        }
        
        if(hours<=h)
            return true;
        return false;
        
    }
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
         int right = 1000000000;
        
        while(left<=right)
        {
              int mid = left + (right - left) / 2;
            
            if(canEat(piles,h,mid)) right= mid-1;
            else left=mid+1;
            
        }
        return left;
    }
};