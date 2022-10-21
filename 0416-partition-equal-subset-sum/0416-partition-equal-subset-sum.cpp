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
        int target=sum/2;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(target+1,false));
        for(int i=0;i<nums.size();i++)
             dp[i][0]=true;
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<=target;j++)
            {
                bool take=false,ntake;
                if(j>= nums[i]) take=dp[i-1][j-nums[i]];
                ntake=dp[i-1][j];
                dp[i][j]=take | ntake;
            }
        }
        return dp[nums.size()-1][target];
    }
};