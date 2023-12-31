class Solution {
public:
    int solve(string &s,string &t,int n,int m,vector<vector<int>> &dp)
    {
        if(m<0) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]) return dp[n][m]= solve(s,t,n-1,m-1,dp)+solve(s,t,n-1,m,dp);
        return dp[n][m]=solve(s,t,n-1,m,dp);
    }
    int numDistinct(string s, string t) {
        int n1=s.size(),n2=t.size();
        vector<vector<double>>dp (n1+4,vector<double>(n2+1,0));
        for(int i=0;i<=n1;i++) dp[i][0]=1;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n1][n2];   
    }
};