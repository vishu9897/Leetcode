class Solution {
public:
    int solve(int i,int j,vector<int>& cuts)
    {
        if(i==j) return 0;
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int cases=cuts[j]-cuts[i-1] + solve(i,k,cuts) + solve(k+1,j,cuts);
            mini=min(mini,cases);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int s=cuts.size();
        vector<vector<int>> dp(s,vector<int>(s,0));
        for(int i=s-1;i>=1;i--)
        {
            for(int j=i+1;j<s;j++)
            {
                int mini=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int cases=cuts[j]-cuts[i-1]+dp[i][k]+dp[k+1][j];
                    mini=min(mini,cases);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][s-1];
    }
};