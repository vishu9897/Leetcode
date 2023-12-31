class Solution {
public:
    int solve(string &s,string &p,int index1,int index2,vector<vector<int>> &dp)
    {
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1]==p[index2]) return dp[index1][index2] = 1 + solve(s,p,index1-1,index2-1,dp);
        return dp[index1][index2]= max(solve(s,p,index1-1,index2,dp), solve(s,p,index1,index2-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        string p=s;
        int n=s.size();
        reverse(p.begin(),p.end());
        vector<vector<int>> dp(n+2,vector<int>(n+3,-1));
        return solve(s,p,n-1,n-1,dp);   
    }
};