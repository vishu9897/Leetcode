class Solution {
public:
    long long solve(vector<int> &nums,int s,int e,vector<vector<long long>>&dp,int flag)
    {
        if(s==e) return 0;
        if(dp[s][flag]!=-1) return dp[s][flag];
        int sign=1;
        if(flag==0) sign=-1;
        long long take= (nums[s] * (sign)) + solve(nums,s+1,e,dp,!flag);
        long long ntake= nums[s] + solve(nums,s+1,e,dp,1);
        return dp[s][flag]=max(take,ntake);
    }
    long long maximumTotalCost(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,-1));
        return solve(nums,0,nums.size(),dp,1);
    }
};