class Solution {
public:
    int solve(vector<int> &nums,int index,int n,vector<int> &dp,int ta){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int take=INT_MIN,ntake=INT_MIN;
        take= nums[index]+ solve(nums,index+2,n,dp,1);
        ntake= solve(nums,index+1,n,dp,0);
        return dp[index]=max(take,ntake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n+4,-1);
        vector<int> dp1(n+4,-1);
        return max(solve(nums,0,n-1,dp,1),solve(nums,1,n,dp1,1));
    }
};