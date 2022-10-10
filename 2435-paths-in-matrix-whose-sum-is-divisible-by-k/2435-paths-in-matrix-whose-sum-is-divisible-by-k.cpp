class Solution {
public:
    int mod=1000000007;
    int solve(vector<vector<int>> &grid,int i,int j,int k,int sum,vector<vector<vector<int>>> &dp)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            sum= (sum+grid[i][j])%k;
            if(sum==0) 
            {
                return 1;
            }
            return 0;
        }
        sum= (sum+grid[i][j])%k;
        if(dp[i][j][sum]!=-1)
        {
            return dp[i][j][sum];
        }
        int t=0,nt=0;
        if(i+1<grid.size())
        {
            t=solve(grid,i+1,j,k,sum,dp);
        }
            
        if(j+1<grid[0].size())
        {
            nt=solve(grid,i,j+1,k,sum,dp);
        }
        return dp[i][j][sum]=(t%mod+nt%mod)%mod;          
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int sum=0,n=grid.size(),m=grid[0].size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k,-1)));
        
        return solve(grid,0,0,k,0,dp);   
    }
};