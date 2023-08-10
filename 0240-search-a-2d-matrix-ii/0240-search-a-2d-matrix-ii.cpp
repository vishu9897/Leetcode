class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int row=0,col=m-1,val;
        while(row<=n-1 && col>=0)
        {
            
            val=matrix[row][col];
            if(val==target) return true;
            if(target<val) col--;
            else row++;
        }
        return false;
    }
};