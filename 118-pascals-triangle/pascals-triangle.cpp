class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vc(rowIndex+1);
        long long temp=1;
        long long nrow=rowIndex+1;
        vc[0]=temp;
        for(int i=1;i<=rowIndex;i++)
        {
            temp=(temp * (nrow-i))/i;
            vc[i]=temp;
        }
        return vc;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++)
        {
             ans.push_back(getRow(i));   
        }
        return ans;

    }
};