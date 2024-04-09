class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1,ans=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        mp[1]=-1;
        mp[2]=-1;

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']=i;
            ans= ans+ min(mp[0],min(mp[1],mp[2]))+1;

        }
        return ans;
    }
};