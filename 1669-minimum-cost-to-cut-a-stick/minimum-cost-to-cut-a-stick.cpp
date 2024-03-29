class Solution {
public:
    int solve(vector<int>& cuts,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            int cases= cuts[j+1] - cuts[i-1] + solve(cuts,i,k-1,dp) + solve(cuts,k+1,j,dp);
            mini= min(mini,cases);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size()+2,vector<int>(cuts.size()+2,0));
        for(int i=cuts.size()-2;i>=1;i--)
        {
            for(int j=1;j<=cuts.size()-2;j++)
            {
                if(i>j) continue;
                int mini=INT_MAX;
                for(int k=i;k<=j;k++)
                {
                    int cost= cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][cuts.size()-2];
    }
};