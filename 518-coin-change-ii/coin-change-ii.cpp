class Solution {
public:
    int solve(int amount,int index,vector<int>&coins,vector<vector<int>> &dp)
    {
        if(index<0) return amount==0 ? 1 : 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int take=0,ntake= solve(amount,index-1,coins,dp);
        if(coins[index] <= amount) take= solve(amount-coins[index],index,coins,dp);
        return dp[index][amount] = take+ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            dp[0][i]= i%coins[0] == 0 ? 1 : 0;
        }
       
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int take=0,ntake=dp[i-1][j];
                if(coins[i] <= j) take=dp[i][j-coins[i]];
                dp[i][j]=take+ntake;
                
            }
        }
        return dp[n-1][amount];
        return solve(amount,coins.size()-1,coins,dp);
    }
};