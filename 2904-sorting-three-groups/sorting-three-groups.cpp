class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int ans=1;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>=nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(dp[i],ans);
                }
            }
        }
        return nums.size()-ans;
    }
};