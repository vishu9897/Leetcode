class Solution {
public:
    bool solve(vector<int> &nums,int target,int index,vector<vector<int>> &dp)
    {
        if(index<0)
        {
            if(target==0) return true;
            return false;
        }
        if(dp[target][index]!=-1) return dp[target][index];
        bool take=false,ntake;
        if(target>= nums[index]) take=solve(nums,target-nums[index],index-1,dp);
        ntake=solve(nums,target,index-1,dp);
        return dp[target][index]=take | ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum%2!=0) return false;
        vector<vector<int>> dp(sum/2+1,vector<int>(nums.size(),-1));
        return solve(nums,sum/2,nums.size()-1,dp);
    }
};