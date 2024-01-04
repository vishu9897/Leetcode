class Solution {
public:
    int solve(vector<int> &cuts,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int cost=cuts[j]-cuts[i-1] + solve(cuts,i,k,dp) + solve(cuts,k+1,j,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        vector<vector<int>> dp(c+2,vector<int>(c+2,-1));
        return solve(cuts,1,c-1,dp);
    }
};