class Solution {
private:
    int solve(vector<int>& coins,int amount,int index,vector<vector<int>>& dp){
        if(index<0) return amount==0 ? 1 : 0;
        if(dp[amount][index]!=-1) return dp[amount][index];
        int take=0,ntake=0;
        if(amount-coins[index]>=0)  take= solve(coins,amount-coins[index],index,dp);   
        ntake= solve(coins,amount,index-1,dp);
        return dp[amount][index]=take+ntake;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int take=0,ntake=dp[i-1][j];
                if(j-coins[i]>=0) take=dp[i][j-coins[i]];
                dp[i][j]=take+ntake;
            }
        }
        return dp[n-1][amount];
    }
};