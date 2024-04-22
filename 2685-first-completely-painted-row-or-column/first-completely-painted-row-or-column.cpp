class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,pair<int,int>> helper;
        vector<int> row(n,m);
        vector<int> col(m,n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                helper[mat[i][j]]=make_pair(i,j);
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            pair<int,int> pr= helper[arr[i]];

            row[pr.first]--;
            col[pr.second]--;
            if(row[pr.first]==0 || col[pr.second]==0) return i;
        }
        for(auto x: row) cout<<x<<" ";
        cout<<endl;
        for(auto x: col) cout<<x<<" ";
        cout<<endl;
        return 0;
    }
};