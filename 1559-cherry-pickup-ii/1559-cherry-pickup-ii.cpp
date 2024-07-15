
class Solution {
private:
int dp[72][72][72];
private:
    int solve(vector<vector<int>> &grid,int rw,int cl1,int cl2,int col[])
    {
        int n=grid.size();
        int m=grid[0].size();
        int sol=0;
        if(rw >= n || cl1>= m || cl2>=m || cl1<0 || cl2<0) return 0;
        if(dp[rw][cl1][cl2]!=-1){
            return dp[rw][cl1][cl2];
        }   
        if(cl1==cl2) sol = grid[rw][cl1];
        else sol = grid[rw][cl1] + grid[rw][cl2];
        int res=INT_MIN;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int tempRes= sol + solve(grid,rw+1,cl1+col[i],cl2+col[j],col);
                res=max(res,tempRes);
            }
        }
        return dp[rw][cl1][cl2]=res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int col[3]= {-1,0,1};
        memset(dp,-1,sizeof(dp));
        
        return solve(grid,0,0,grid[0].size()-1,col);   
    }
};