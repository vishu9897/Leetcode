class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,n=s.size(),maxFreq=INT_MIN,maxLength=INT_MIN;
        map<int,int> mp;
        while(right<n)
        {
            mp[s[right]-'A']++;
            maxFreq=max(maxFreq,mp[s[right]-'A']);
            if((right-left+1)-maxFreq > k)
            {
                mp[s[left]-'A']--;
                maxFreq=0;
                for(int i=0;i<26;i++)
                {
                    maxFreq=max(mp[i],maxFreq);
                }
                left++;
            }
            if((right-left+1)-maxFreq <= k)
                maxLength=max(maxLength,right-left+1);
            right++;
        }   
        return maxLength;

    }
};