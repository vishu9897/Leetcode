class Solution {

public:
    int mod=1e9+7;
    int solve(vector<int> &nums,int index,int mask,vector<vector<int>> &dp)
    {
        if(mask == (1<<nums.size())-1) return 1;
        if(dp[index][mask]!=-1) return dp[index][mask];
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mask & (1<<i)) continue;
            if(mask==0||(nums[index]%nums[i]==0 || nums[i]%nums[index]==0))
            {
                res = (res%mod + solve(nums,i,mask | 1<<i,dp)%mod) %mod;
            }
            
        }
        return dp[index][mask]=res;
    }
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(1<<(n+5),-1));
        return solve(nums,0,0,dp);   
    }
};