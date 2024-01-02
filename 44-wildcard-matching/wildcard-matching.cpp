class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n1=s.size(),n2=p.size();
        vector<vector<bool>> dp(n1+2,vector<bool>(n2+4,false));
        for(int i=1;i<=n2;i++) {
            if(p[i-1]!='*') break;
            dp[0][i]=true;
        }
        dp[0][0]=true;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]= dp[i-1][j] | dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n1][n2];
    }
};