class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        vector<int> prev(n2+1,0),curr(n2+1,0);
        int ans=INT_MIN;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }
                else
                    curr[j]=0;
                ans= max(ans,curr[j]);
            }
            prev=curr;
        }
        return ans;
    }
};