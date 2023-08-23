class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<vector<int>>> vc(n);
        vector<int> dp(n+1,0);
        for(auto &x:offers)
        {
            vc[x[1]].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            for(auto &x: vc[i-1])
            {
                dp[i]=max(dp[i],dp[x[0]]+x[2]);
            }
        }
        return dp[n];
    }

};