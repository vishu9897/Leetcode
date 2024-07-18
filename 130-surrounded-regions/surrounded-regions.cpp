class Solution {
public:
    int cl[4]={0,-1,1,0};
    int rw[4]={-1,0,0,1};
    void solve(vector<vector<char>> &board,int row,int col,vector<vector<char>> &ans,vector<vector<int>> &vis)
    {
        int n=board.size();
        int m=board[0].size();

        ans[row][col]='O';

        vis[row][col]=1;

        for(int k=0;k<4;k++)
        {
            int r = row + rw[k];
            int c = col + cl[k];

            if(r>=0 && r < n && c>=0 && c < m && board[r][c]=='O' && vis[r][c]==0)
            {
                solve(board,r,c,ans,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<char>> ans(n,vector<char>(m,'X'));
        // vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            vector<vector<int>> vis(n,vector<int>(m,0));
            if(board[i][0]=='O'){
                solve(board,i,0,ans,vis);
            } 
        }
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> vis(n,vector<int>(m,0));
            if(board[i][m-1]=='O'){
                solve(board,i,m-1,ans,vis);
            }   
        }
        for(int j=0;j<m;j++)
        {
            vector<vector<int>> vis(n,vector<int>(m,0));
            if(board[0][j]=='O'){
                solve(board,0,j,ans,vis);
            }
        }
        for(int j=0;j<m;j++)
        {
            vector<vector<int>> vis(n,vector<int>(m,0));
            if(board[n-1][j]=='O'){
                solve(board,n-1,j,ans,vis);
            } 
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j]=ans[i][j];
            }
        }

    }

};