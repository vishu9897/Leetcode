class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                } 
                
            }
        }
        int rw[4]={-1,0,0,1};
        int cl[4]={0,-1,1,0};
        while(!q.empty())
        {
            pair<pair<int,int>,int> pr=q.front();
            q.pop();


            int i=pr.first.first;
            int j=pr.first.second;
            int step=pr.second;
            ans[i][j]=step;

            for(int k=0;k<4;k++)
            {
                int row= rw[k] + i;
                int col= cl[k] + j;

                if(row>=0 && row<n && col>=0 && col<m){
                    if(vis[row][col]==0 && mat[row][col]==1)
                    {
                        vis[row][col]=1;
                        q.push({{row,col},step+1});
                    }
                }

            }

        }
        return ans;
    }
};