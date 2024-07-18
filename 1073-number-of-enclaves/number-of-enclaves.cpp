class Solution {
public:
    int rw[4]={-1,0,0,1};
    int cl[4]={0,-1,1,0};
    void solve(int row,int col,vector<vector<int>> &grid)
    {   
        grid[row][col]=0;
        int n=grid.size(),m=grid[0].size();
        for(int k=0;k<4;k++)
        {
            int r= row + rw[k];
            int c= col + cl[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1)
            {
                solve(r,c,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1) solve(i,j,grid);
                }
            }
        }
        int res=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) res++;
            }
        }

        return res;
    }
};