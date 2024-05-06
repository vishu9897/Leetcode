class Solution {
public:
    int solve(vector<int> &cuts,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int cases= cuts[j]-cuts[i-1] + solve(cuts,i,k,dp) + solve(cuts,k+1,j,dp);
            mini=min(cases,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(cuts,1,cuts.size()-1,dp);
    }
};