class Solution {
public:
    int minDeletions(string s) {
        map<int,int> mp;
        int ans=0;
        int cnt=0;
        sort(s.begin(),s.end());
        char ch=s[0];
        for(int i=0;i<s.length();i++){
            if(s[i]==ch){
                cnt++;
            }else{
                int x = cnt;
                while(mp.count(cnt)!=0 && cnt!=0){
                    cnt--;
                }
                mp[cnt]=1;
                ans += (x-cnt);
                ch=s[i];
                cnt=1;
            }
        }
        int x = cnt;
        while(mp.count(cnt)!=0 && cnt!=0){
            cnt--;
        }
        ans += (x-cnt);
        return ans;
    }
};