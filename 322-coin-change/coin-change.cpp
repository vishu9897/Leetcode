class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans;
        vector<vector<int>> dp(n+3,vector<int>(amount+2,INT_MAX));
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int i=0;i<=amount;i++) if(i%coins[0]==0) dp[0][i]=i/coins[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                long long take=INT_MAX,ntake= dp[i-1][j];
                if(j>=coins[i]) take=(long long) 1+ dp[i][j-coins[i]];
                dp[i][j]=min(take,ntake);
            }
        }
        ans=dp[n-1][amount];
        return ans>=INT_MAX ? -1 : ans;
    }
};