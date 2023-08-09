class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),ans=0;
        vector<int> vc;
        vc.push_back(0);
        vc.push_back(0);
        for(int i=0;i<n;i++)
        sort(mat[i].begin(),mat[i].end());
        for(int i=0;i<n;i++)
        {
            int low=0,high=m-1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(mat[i][mid]==1) high=mid-1;
                else low=mid+1;
            }
            if(m-low>ans)
            {
                ans=m-low;
                vc.clear();
                vc.push_back(i);
                vc.push_back(m-low);
            }
        }
        return vc;
    }
};