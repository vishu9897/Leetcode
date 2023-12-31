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
        vector<vector<int>>dp (n1+4,vector<int>(n2+1,-1));
        return solve(s,t,n1,n2,dp);   
    }
};