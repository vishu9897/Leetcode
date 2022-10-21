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
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,0));
        int n=grid.size();
        int m=grid[0].size();
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int t1=INT_MAX,t2=INT_MAX;
                
                if(i==n-1 && j==m-1) continue;
                if(i+1<n)
                t1 = grid[i][j] + dp[i+1][j];
                if(j+1<m)
                t2 = grid[i][j] + dp[i][j+1];

                dp[i][j]=min(t1,t2);
            }
        }
        return dp[0][0];   
    }
};