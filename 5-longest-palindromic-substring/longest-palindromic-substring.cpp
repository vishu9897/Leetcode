class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),ind=0,res=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(gap==0) dp[i][j]=true;
                else if(gap==1) dp[i][j] = s[i]==s[j] ? true : false;
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=true;
                }
                if(dp[i][j])
                {
                    ind =i;
                    res= gap+1;
                }
            }
        }
        return s.substr(ind,res);
    }
};