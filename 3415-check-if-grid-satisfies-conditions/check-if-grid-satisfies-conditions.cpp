class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int prev=-1;
        int n=grid.size();
        int m=grid[0].size();
    
        for(int i=0;i<m;i++)
        {
            int num=grid[0][i];
            if(prev==num) return false;
            prev=num;
            for(int j=1;j<n;j++)
            {
                if(num!=grid[j][i]) return false;
            }
        }
        return true;
    }
};