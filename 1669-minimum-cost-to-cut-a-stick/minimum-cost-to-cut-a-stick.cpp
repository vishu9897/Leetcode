class Solution {
public:
    int solve(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
    {
        if(i >= j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
           int cases= cuts[j]-cuts[i-1] + solve(i,k,cuts,dp) + solve(k+1,j,cuts,dp);
           mini=min(cases,mini);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),0));
        for(int i=cuts.size()-1;i>=1;i--)
        {
            for(int j=0;j<cuts.size();j++)  {
                if(i>=j) continue;
                int mini=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int cases= cuts[j]-cuts[i-1] + dp[i][k] + dp[k+1][j];
                    mini=min(cases,mini);
                }
                dp[i][j]=mini; 
            }
        }
        return dp[1][cuts.size()-1];
    }
};