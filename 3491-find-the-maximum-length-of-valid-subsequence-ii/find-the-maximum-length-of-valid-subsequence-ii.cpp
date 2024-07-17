class Solution {
public:

    int maximumLength(vector<int>& nums, int div) {
        int n = nums.size();
        vector<int> dp(div,0);
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % div; 
        }
        
        int res = 1;
        for(int j=0;j<div;j++)
        {
            for(int i=0;i<n;i++)
            {
                int prev= (j - nums[i]+div)%div;
                // dp[nums[i]]=max(dp[nums[i]],1+dp[prev]);
                dp[nums[i]]=1+dp[prev];
                res=max(res,dp[nums[i]]);
            }
            for(int i=0;i<dp.size();i++) dp[i]=0;
        }
        
        return res;
    }
};