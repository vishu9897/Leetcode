class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int j=1;j<=k;j++)
                {
                    if(buy) dp[i][buy][j]=max(-prices[i]+ dp[i+1][0][j] , dp[i+1][1][j]);
                    else dp[i][buy][j]=max(prices[i]+ dp[i+1][1][j-1] , dp[i+1][0][j]);
                }
            }
        }
        return dp[0][1][k];
    }
};