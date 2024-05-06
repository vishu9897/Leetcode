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
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins.size()-1,coins,dp);
    }
};