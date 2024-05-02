class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int res=-1;
        int noOfOne=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) noOfOne++;
            }
        }
        if(noOfOne==0) return 0;
        int rw[4]={-1,0,0,1};
        int cl[4]={0,-1,1,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty())
        {
            int s=q.size();
            res++;
            
            for(int in=0;in<s;in++)
            {
                pair<int,int> pr=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int row= pr.first + rw[i];
                    int col= pr.second + cl[i];
                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && vis[row][col]==0){
                        vis[row][col]=1;
                        noOfOne--;
                        q.push({row,col});
                    }
                }
            }
        }
        cout<<noOfOne<<endl;

        if(noOfOne > 0) return -1;
        return res;
    }
};