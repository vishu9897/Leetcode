class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=k;j++)
            {
                for(int buy=0;buy<=1;buy++)
                {
                    if(buy) dp[i][j][buy]=max(-prices[i]+ dp[i+1][j][0] , dp[i+1][j][1]);
                    else dp[i][j][buy]=max(prices[i]+ dp[i+1][j-1][1] , dp[i+1][j][0]);
                }
            }
        }
        return dp[0][k][1];
    }
};