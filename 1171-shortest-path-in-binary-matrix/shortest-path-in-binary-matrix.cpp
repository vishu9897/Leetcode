class Solution {
private:
    int row[8]={-1,-1,-1,0,0,1,1,1};
    int col[8]={-1,0,1,-1,1,-1,0,1};
public:

    int solve(vector<vector<int>> &grid,int rw,int cl,vector<vector<int>>& vis)
    {
        vis[rw][cl]=1;
        int n=grid.size();
        int m=grid[0].size();
        if(rw==n-1 && cl==m-1) return 1;
        int res=INT_MAX;
        for(int i=0;i<8;i++)
        {
            int r= rw + row[i];
            int c= cl + col[i];

            if(r<n && c<m && r>=0 && c>=0 && vis[r][c]==0 && grid[r][c]==0)
            {
                cout<<r<<" "<<c<<endl;
                int temp=1 + solve(grid,r,c,vis);
                res=min(res,temp);
            }
        }
        return res;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        queue<pair<pair<int,int>,int>>q;

        q.push({{0,0},1});
        vis[0][0]=1;

        while(!q.empty())
        {
            pair<pair<int,int>,int> frontNode = q.front();
            q.pop();
            int rw= frontNode.first.first;
            int cl= frontNode.first.second;
            int step= frontNode.second;
        
            if(rw==n-1 &&cl==m-1) return step;
            for(int i=0;i<8;i++)
            {
                int r= rw + row[i];
                int c= cl + col[i];

                if(r<n && c<m && r>=0 && c>=0 && vis[r][c]==0 && grid[r][c]==0)
                {
                    vis[r][c]=1;
                    q.push({{r,c},step+1});
                }
            }

        }

        return -1;
    }
};