class Solution {
public:
    bool solve(vector<vector<int>> &dist,vector<vector<int>> &vis,int mid,int i,int j)
    {
        if(dist[i][j]<mid || dist[i][j]==INT_MAX)  return false;
        int n=dist.size(),m=dist[0].size();
        int maxi=INT_MIN;
        vis[i][j]=1;
        if(i==n-1 && j==m-1) return true;
        bool ans1=false,ans2=false,ans3=false,ans4=false;
        if(i+1 < n && vis[i+1][j]==0 && dist[i+1][j]>=mid)
        {
            ans1= solve(dist,vis,mid,i+1,j);
        }
        if(j+1 < m && vis[i][j+1]==0 && dist[i][j+1]>=mid)
        { 
            ans2= solve(dist,vis,mid,i,j+1);
        }
        if(i-1 >= 0 && vis[i-1][j]==0 && dist[i-1][j]>=mid)
        {
            ans3= solve(dist,vis,mid,i-1,j);
        }
        if(j-1 >=0  && vis[i][j-1]==0 && dist[i][j-1]>=mid)
        {
            ans4= solve(dist,vis,mid,i,j-1);
        }
        return  ans1 || ans2 || ans3 || ans4;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<pair<int,int>> pr;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int low=0,high=0,ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) pr.push_back({i,j});
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0){
                    int mini=INT_MAX;
                    for(auto x:pr)
                    {
                        mini=min(mini,abs(x.first-i) + abs(x.second-j));
                    }
                    grid[i][j]=mini;
                    high=max(high,mini);
                }
                else
                {
                    grid[i][j]=INT_MIN;
                }
            }
        }
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            if(solve(grid,vis,mid,0,0))
            {
                ans=max(ans,mid);
                low=mid+1;
               
            }
            else
            {
                 high=mid-1;
            }
            for(int i=0;i<vis.size();i++)
            {
                for(int j=0;j<vis[0].size();j++)
                {
                    vis[i][j]=0;
                }
            }
        }
        return high==-1 ? 0 : high;
        
    }
};