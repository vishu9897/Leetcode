class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        for(int i=0;i<4;i++)
        {
            if(s1[i]!=s2[i] && s1[i]!=s2[(i+2)%4])
            return false;
        }
        return true;
    }
};