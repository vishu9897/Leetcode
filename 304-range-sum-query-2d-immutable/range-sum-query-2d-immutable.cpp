class NumMatrix {
private:
    vector<vector<long long>> helpMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        helpMatrix.resize(n,vector<long long>(m));
        long long sum;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum=0;
                sum += matrix[i][j];
                if((i-1) >= 0)
                {
                    sum+= helpMatrix[i-1][j];
                }
                if((j-1) >= 0)
                {
                    sum+= helpMatrix[i][j-1];
                }
                if(i-1 >=0 && j-1>=0) sum -= helpMatrix[i-1][j-1];  
                helpMatrix[i][j]=sum;
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int n=helpMatrix.size();
        int m=helpMatrix[0].size();
        int diff1=0,diff2=0,add=0;
        diff1 = col1-1 >= 0 ? helpMatrix[row2][col1-1] : 0;
        diff2 = row1-1 >= 0 ? helpMatrix[row1-1][col2] : 0;
        add = row1-1 >=0 && col1-1>=0 ? helpMatrix[row1-1][col1-1] : 0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<helpMatrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<helpMatrix[row2][col2]<<" "<<diff1<<" "<<diff2<<" "<<add<<endl<<endl;
        return helpMatrix[row2][col2] - diff1 -diff2 + add; 

        return 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */