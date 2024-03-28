class Solution {
public:
    int solve(string text1,string text2,int index1,int index2,vector<vector<int>> &dp)
    {
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(text1[index1]==text2[index2]) return dp[index1][index2] = 1+ solve(text1,text2,index1-1,index2-1,dp);
        else return dp[index1][index2]= 0 + max(solve(text1,text2,index1-1,index2,dp),solve(text1,text2,index1,index2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1]) dp[i][j]= 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};