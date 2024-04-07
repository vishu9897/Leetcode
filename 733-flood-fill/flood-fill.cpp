class Solution {
public:
    void DFS(vector<vector<int>> &img,int sr,int sc,int color,int initCol,int n,int m,vector<vector<int>> &ans,int drow[],int dcol[])
    {
        ans[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int row= sr +drow[i];
            int col= sc+ dcol[i];
            if(row>=0 && row<n && col>=0 && col<m && ans[row][col]==initCol)
            {
                DFS(img,row,col,color,initCol,n,m,ans,drow,dcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int initCol = image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        if(color==initCol) return ans;
        DFS(image,sr,sc,color,initCol,n,m,ans,drow,dcol);
        return ans;
    }
};