class Solution {
public:
    int solve(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        int t1=INT_MAX,t2=INT_MAX;
        if(i==n-1 && j== m-1) return grid[i][j];
        if(i+1<n)
        {
           t1 = grid[i][j] + solve(grid,i+1,j,dp);
        }
        if(j+1<m)
        {
            t2 = grid[i][j] + solve(grid,i,j+1,dp);
        }
        return dp[i][j]=min(t1,t2);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
      return solve(grid,0,0,dp);   
    }
};