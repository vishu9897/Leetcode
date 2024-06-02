class Solution {
public:
    int solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<j;k++)
        {
            int cases= nums[i-1]*nums[j]*nums[k] + solve(nums,i,k,dp) + solve(nums,k+1,j,dp);
            maxi=max(maxi,cases);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+2,0));
        for(int i=nums.size()-1;i>=1;i--)
        {
            for(int j=1;j<nums.size();j++)
            {
                if(i>=j) continue;
                int maxi=INT_MIN;
                for(int k=i;k<j;k++)
                {
                    int cases= nums[i-1]*nums[j]*nums[k] + dp[i][k] + dp[k+1][j];
                    maxi=max(maxi,cases);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][nums.size()-1];
        return solve(nums,1,nums.size()-1,dp);
    }
};