class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        for(int i=0;i<n1;i++)
        {
            if(text2[0]==text1[i]){
                dp[i][0]=1;
            }
            if(i!=0 && dp[i-1][0]==1) dp[i][0]=1;
        }
        for(int i=0;i<n2;i++)
        {
            if(text1[0]==text2[i]){
                dp[0][i]=1;
            }
            if(i!=0 && dp[0][i-1]==1) dp[0][i]=1;
        }
        // for(int i=0;i<n1;i++)
        // {
        //     for(int j=0;j<n2;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=1;i<n1;i++)
        {
            for(int j=1;j<n2;j++)
            {
                if(text1[i]==text2[j]) dp[i][j]= 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1-1][n2-1];
    }
};