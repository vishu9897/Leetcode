class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        for(auto x: s)
        {
            if(x=='i' || x=='a' || x=='e' || x=='o' || x=='u')
            cnt++;
        }
        if(cnt>0) return true;
        return false;
    }
};