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
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(1,cuts.size()-1,cuts,dp);
    }
};