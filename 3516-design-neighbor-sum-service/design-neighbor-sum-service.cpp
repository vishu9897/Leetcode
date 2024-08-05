class neighborSum {
public:
    map<int,pair<int,int>> mp;
    
    neighborSum(vector<vector<int>>& grid) {

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                mp[grid[i][j]]= {findDiagonalSum(i,j,grid),findAdjacentSum(i,j,grid)};
            }
        }   
    }
    
    int findDiagonalSum(int i,int j,vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int sum=0;
        if(i-1 >= 0 && j-1 >= 0)sum+=grid[i-1][j-1];
        if(i-1 >= 0 && j+1 < m) sum+=grid[i-1][j+1];
        if(i+1 < n && j-1 >=0)  sum+= grid[i+1][j-1];
        if(i+1 < n && j+1 < m)  sum+= grid[i+1][j+1];
        return sum;
    }

    int findAdjacentSum(int i,int j,vector<vector<int>> &grid)
    {
        int n= grid.size();
        int m= grid[0].size();
        int sum=0;
        if(i-1 >= 0)sum+=grid[i-1][j];
        if(j+1 < m) sum+=grid[i][j+1];
        if(j-1 >=0) sum+= grid[i][j-1];
        if(i+1 < n) sum+= grid[i+1][j];
        return sum;
    }
    
    int adjacentSum(int value) {
        return mp[value].second;     
    }
    
    int diagonalSum(int value) {
        return mp[value].first;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */