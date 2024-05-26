class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++)
        {
            int take=nums[i],ntake=0;
            if(i-2 >= 0) take +=dp[i-2];
            if(i-1 >= 0) ntake +=dp[i-1];
            dp[i]=max(take,ntake);
        }
        return dp[n-1];
    }
};