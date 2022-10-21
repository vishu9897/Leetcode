class Solution {
public:
    int solve(vector<int> &coins,int amount,int index,vector<vector<int>> &dp){
        if(index==0)
        {
            if(amount%coins[0]==0)
            return amount/coins[0];
            return 1e9;
        }
        if(dp[amount][index]!=-1) return dp[amount][index];
        int take=1e9,ntake;
        if(amount>=coins[index]) take= 1+ solve(coins,amount-coins[index],index,dp);
        ntake=0 +solve(coins,amount,index-1,dp);
        return dp[amount][index]=min(take,ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
       int ans= solve(coins,amount,coins.size()-1,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};