class Solution {
public:
    int solve(int n1,int n2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(n1<0 || n2<0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        int take=INT_MIN,ntake;
        if(s1[n1]==s2[n2]) take= 1+solve(n1-1,n2-1,s1,s2,dp);
        ntake= max(solve(n1,n2-1,s1,s2,dp),solve(n1-1,n2,s1,s2,dp));
        return dp[n1][n2]=max(take,ntake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};