class Solution {
public:
    bool solve(vector<int> &nums,int n,int index,int sum,vector<vector<int>> &dp)
    {
        if(index>=n)
        {
            if(sum==0) return true;
            return false;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool take=false,ntake;
        if(sum-nums[index]>=0)
        take=solve(nums,n,index+1,sum-nums[index],dp);
        ntake=solve(nums,n,index+1,sum,dp);
        return dp[index][sum]=take|ntake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        sum=sum/2;
        vector<vector<int>> dp(nums.size()+10,vector<int>(sum+1,-1));
        return solve(nums,n,0,sum,dp);   
    }
};