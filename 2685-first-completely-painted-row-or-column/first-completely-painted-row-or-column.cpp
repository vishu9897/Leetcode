class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        int ans=INT_MAX;

        unordered_map<int,int> mp;

        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        }

        for(int i=0;i<n;i++)
        {
            count=0;
            for(int j=0;j<m;j++)
            {
                count= max(count,mp[mat[i][j]]);
            }
            ans=min(ans,count);
        }

        for(int i=0;i<m;i++){
            count=0;
            for(int j=0;j<n;j++)
            {
                count=max(count,mp[mat[j][i]]);
            }
            ans=min(ans,count);
        }

        return ans;
    }
};