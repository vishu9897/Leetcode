class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int low=0,ans=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']++;
            while((mp[s[i]-'a']) > 1)
            {
                mp[s[low]-'a']--;
                low++; 
            }
            ans=max(ans,i-low+1);
        }
        return ans == INT_MIN ? 0 : ans;
    }
};