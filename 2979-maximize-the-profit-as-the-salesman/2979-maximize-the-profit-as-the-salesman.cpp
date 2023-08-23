class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<vector<int>>> vc(n);
        vector<int> dp(n+1,0);
        for(auto &x:offers)
        {
            vc[x[1]].push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            dp[i+1]=dp[i];
            for(auto &x: vc[i])
            {
                dp[i+1]=max(dp[i+1],dp[x[0]]+x[2]);
            }
        }
        return dp[n];
    }

};