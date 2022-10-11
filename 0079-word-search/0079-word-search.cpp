class Solution {
public:
    bool solve(vector<vector<char>>& board,string &word,int i,int j,int index,vector<vector<int>> &vis)
    {
        if(index==word.size()) return true;
        if(i+1 < board.size() && board[i+1][j]==word[index] && vis[i+1][j]==0)
        {
            vis[i+1][j]=1;
            if(solve(board,word,i+1,j,index+1,vis)) return true;
            vis[i+1][j]=0;
        }
        if(i-1 >= 0 && board[i-1][j]==word[index] && vis[i-1][j]==0)
        {
            vis[i-1][j]=1;
            if(solve(board,word,i-1,j,index+1,vis)) return true;
            vis[i-1][j]=0;
        }
        if(j+1 < board[0].size() && board[i][j+1]==word[index] && vis[i][j+1]==0)
        {
            vis[i][j+1]=1;
            if(solve(board,word,i,j+1,index+1,vis)) return true;
            vis[i][j+1]=0;
        }
        if(j-1 >=0 && board[i][j-1]==word[index] && vis[i][j-1]==0)
        {
            vis[i][j-1]=1;
            if(solve(board,word,i,j-1,index+1,vis)) return true;
            vis[i][j-1]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    vis[i][j]=1;
                    if(solve(board,word,i,j,1,vis)) return true;
                    vis[i][j]=0;
                } 
            }
        }
        return false;
    }
};