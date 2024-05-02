class Solution {
private:
    int nrow[4]={-1,0,0,1};
    int ncol[4]={0,1,-1,0};
    

    void solve(vector<vector<char>>&grid,vector<vector<int>> &vis,int row,int col,int n,int m)
    {
        
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int rw= row + nrow[i];
            int cl= col + ncol[i];
            if(rw>=0 && rw<n && cl>=0 && cl<m && grid[rw][cl]=='1' && vis[rw][cl]==0)
            {
                solve(grid,vis,rw,cl,n,m);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    solve(grid,vis,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};