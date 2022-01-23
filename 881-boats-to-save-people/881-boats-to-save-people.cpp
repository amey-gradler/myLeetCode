class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int boats=0;
        int low=0;
        int high = people.size()-1;
        int n = people.size();
        sort(people.begin(),people.end());
        while(low<=high)
        {
            boats++;
            if(low==high) break;
            int w = people[low]+people[high];
            if(w<=limit){
                low++;
                high--;
            }
            else
            {
                high--;
            }
        
        }
        return boats;
        
    }
};