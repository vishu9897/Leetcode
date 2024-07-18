class Solution {
public:
    int cl[4]={0,-1,1,0};
    int rw[4]={-1,0,0,1};
    void solve(vector<vector<char>> &board,int row,int col,vector<vector<char>> &ans)
    {
        int n=board.size();
        int m=board[0].size();

        ans[row][col]='O';

        for(int k=0;k<4;k++)
        {
            int r = row + rw[k];
            int c = col + cl[k];

            if(r>=0 && r < n && c>=0 && c < m && board[r][c]=='O' && ans[r][c]=='X')
            {
                solve(board,r,c,ans);
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
            if(board[i][0]=='O'){
                solve(board,i,0,ans);
            } 
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O'){
                solve(board,i,m-1,ans);
            }   
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O'){
                solve(board,0,j,ans);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(board[n-1][j]=='O'){
                solve(board,n-1,j,ans);
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