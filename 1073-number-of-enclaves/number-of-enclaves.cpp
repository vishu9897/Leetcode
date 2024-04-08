class Solution {
public:
    void Dfs(vector<vector<int>>& grid, vector<vector<int>> &visited,int drow[],int dcol[],int sr,int sc,int n,int m)
    {
        visited[sr][sc]=1;
        for(int i=0;i<4;i++)
        {
            int row= sr + drow[i];
            int col= sc + dcol[i];

            if(row>=0 && row<n && col>=0 && col<m && visited[row][col]==0 && grid[row][col]==1)
            {
                Dfs(grid,visited,drow,dcol,row,col,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int res=0;

        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1) && visited[i][j]==0 && grid[i][j]==1)
                {
                    Dfs(grid,visited,drow,dcol,i,j,n,m);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1) res++;
            }
        }

        return res;
    }
};