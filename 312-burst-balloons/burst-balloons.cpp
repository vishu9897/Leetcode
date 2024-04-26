class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j) return 0;
        int maxCost=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<j;k++)
        {
            int cost= (nums[i-1] * nums[k] * nums[j]) + solve(nums,i,k,dp) + solve(nums,k+1,j,dp);
            maxCost= max(maxCost,cost);
        }
        return dp[i][j]=maxCost;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,1,n-1,dp);
        // return 0;
    }
};