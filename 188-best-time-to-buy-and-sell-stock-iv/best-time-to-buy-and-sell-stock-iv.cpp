class Solution {
public:
    int solve(vector<int> &prices,int k,int buy,int index,vector<vector<vector<int>>> &dp)
    {
        if(prices.size()<=index || k==0) return 0;
        if(dp[index][k][buy]!=-1)return dp[index][k][buy];
        if(buy) return dp[index][k][buy]= max(-prices[index] + solve(prices,k,0,index+1,dp), solve(prices,k,1,index+1,dp));
        else return dp[index][k][buy]=max(prices[index] + solve(prices,k-1,1,index+1,dp), solve(prices,k,0,index+1,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(k+2,vector<int>(3,-1)));
        return solve(prices,k,1,0,dp);
    }
};