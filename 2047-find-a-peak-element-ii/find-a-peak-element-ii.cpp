class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int i=0,j=0;
        while(i>=0 && i<row && j>=0 && j<col)
        {
            int up= i-1<0 ? -1 : mat[i-1][j];
            int down= i+1>=row ? -1 : mat[i+1][j];
            int left= j-1<0 ? -1 : mat[i][j-1];
            int right= j+1>=col ? -1 : mat[i][j+1];
            if(mat[i][j]>up && mat[i][j]>right && mat[i][j]>left && mat[i][j]>down) return {i,j};
            int maxi=max({up,down,left,right});
            if(maxi==up) i--;
            else if(maxi==down) i++;
            else if(maxi==left) j--;
            else if(maxi==right) j++;

        }
        return {-1,-1};
    }
};