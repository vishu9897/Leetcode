class Solution {
public:
    int solve(vector<int> &prices,int index,int buy,vector<vector<int>> &dp)
    {
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy) return dp[index][buy] = max(-prices[index]+solve(prices,index+1,0,dp),0 + solve(prices,index+1,1,dp));
        else return dp[index][buy] = max(prices[index]+solve(prices,index+2,1,dp),0 + solve(prices,index+1,0,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+3,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};