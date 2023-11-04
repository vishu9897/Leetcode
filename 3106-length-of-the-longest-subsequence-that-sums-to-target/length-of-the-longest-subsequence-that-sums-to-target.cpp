class Solution {
public:
    int solve(int index,int target, vector<int> &nums,vector<vector<int>> &dp)
    {
        if(index<0)
        {
            if(target==0) return 0;
            return INT_MIN;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int take=INT_MIN,ntake=INT_MIN;
        if(target-nums[index]>=0)
            take=1+ solve(index-1,target-nums[index],nums,dp);
        ntake=solve(index-1,target,nums,dp);
        return dp[index][target] = max(take,ntake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+2,vector<int>(target+3,-1));
        long long res= solve(nums.size()-1,target,nums,dp);
        return res<=0?-1 : res;
    }
};