class Solution {
public:
    long long solve(vector<int>& nums,int index,int x,int parity,vector<vector<long long>>&dp)
    {
        if(index>=nums.size()) return 0;
        if(dp[index][parity]!=-1) return dp[index][parity];
        int subs = nums[index]%2==0 ? 1: 0;
        int diff;
        if(subs==parity) diff=0;
        else diff=x;
        long long take= nums[index] - diff + solve(nums,index+1,x,subs,dp);
        long long ntake = solve(nums,index+1,x,parity,dp);
        return dp[index][parity] = max(take,ntake);
    }
    long long maxScore(vector<int>& nums, int x) {
        int parity= nums[0]%2==0 ? 1 : 0;
        vector<vector<long long>> dp(nums.size()+2,vector<long long>(2,-1));
        return nums[0]+solve(nums,1,x,parity,dp);   
    }
};