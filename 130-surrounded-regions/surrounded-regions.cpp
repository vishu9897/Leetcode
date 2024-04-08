class Solution {
public:
    void DFS(vector<vector<char>>&board,vector<vector<int>>& visited,int m,int n,int rw,int cl,int drow[],int dcol[],vector<vector<char>> &ans)
    {
        ans[rw][cl]='O';
        visited[rw][cl]=1;

        for(int i=0;i<4;i++)
        {
            int row= rw + drow[i];
            int col= cl + dcol[i];   
            if(row>=0 && col>=0 && row<n && col<m && board[row][col]=='O' && visited[row][col]!=1)
            {
                DFS(board,visited,m,n,row,col,drow,dcol,ans);
            }
        }
        

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        int drow[]= {-1,0,0,1};
        int dcol[]= {0,-1,1,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && (i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O')
                {
                    DFS(board,visited,m,n,i,j,drow,dcol,ans);
                }

            }
        }
        board= ans;
    }
};