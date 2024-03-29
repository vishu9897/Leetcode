class Solution {
public:
   
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>> dp(n+2,vector<bool>(m+2,false));
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')break;
            dp[0][i]=true;
        }
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]= dp[i-1][j] | dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};