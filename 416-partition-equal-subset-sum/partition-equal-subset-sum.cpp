class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        sum=sum/2;
        vector<vector<bool>> dp(nums.size()+10,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)
        {
          dp[i][0]=true;   
        }
        if(nums[0]==sum) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++)
            {
                bool take= false,ntake=true;
                if(nums[i]<=j) take=dp[i-1][j-nums[i]];
                ntake=dp[i-1][j];
                dp[i][j]= take | ntake;
            }
        }
        return dp[n-1][sum];   
    }
};