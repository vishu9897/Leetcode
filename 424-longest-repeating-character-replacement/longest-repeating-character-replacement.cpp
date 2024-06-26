class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26];
        for(int i=0;i<26;i++) mp[i]=0;
        int low=0,n=s.size(),res=INT_MIN;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'A']++;
            int maxi=INT_MIN;
            for(int j=0;j<26;j++)
            {
                maxi=max(maxi,mp[j]);
            }
            if((i-low+1-maxi) > k) {
                mp[s[low]-'A']--;
                low++;
            }
            if((i-low+1-maxi) <=k)
            res=max(res,i-low+1);
        }
        return res;

    }
};