class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> res(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int row[4]= {-1,0,0,1};
        int col[4]= {0,-1,1,0};

        while(!q.empty()){
            int rw= q.front().first.first;
            int cl= q.front().first.second;
            int step= q.front().second;
            q.pop();

            res[rw][cl]=step;

            for(int k=0;k<4;k++)
            {
                int fr= rw + row[k];
                int fc= cl + col[k];

                if(fr>=0 && fc >=0 && fr<n && fc<m && mat[fr][fc]==1 && vis[fr][fc]==0)
                {
                    vis[fr][fc]=1;
                    q.push({{fr,fc},step+1});
                } 
            }

        }

        return res;
    }
};