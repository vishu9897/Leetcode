class Solution {
public:
    bool checkString(int freq[])
    {
        int minFreq=-1;
        for(int i=0;i<26;i++)
        {
            if(minFreq==-1 && freq[i]!=0)
            {   
                minFreq=freq[i];
            }
            if(minFreq!=freq[i] && freq[i]!=0)
            {
                return false;
            }   
        }
        return true;

    }
    int solve(string&s,int index,int n,vector<int> &dp)
    {
        if(n<=index) return 0;
        int ans=INT_MAX;
        if(dp[index]!=-1) return dp[index];
        int freq[26]={0};
        for(int i=index;i<n;i++)
        {
            freq[s[i]-'a']++;
            if(checkString(freq))
            {
                int calculate= 1 + solve(s,i+1,n,dp);
                ans=min(ans,calculate);
            }
        }
        return dp[index]=ans;
    }
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0,n,dp);
    }
};