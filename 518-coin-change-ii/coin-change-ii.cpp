class Solution {
public:
    int solve(vector<int> &coins,int index,int amount,vector<vector<int>> &dp)
    {
        if(index<0){ 
            return amount==0 ? 1 : 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int take=0,ntake=0;
        if(coins[index]<=amount) take=solve(coins,index,amount-coins[index],dp);
        ntake= solve(coins,index-1,amount,dp);
        return dp[index][amount]=take+ntake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+2,-1));
        return solve(coins,coins.size()-1,amount,dp);
    }
};