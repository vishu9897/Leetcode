class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sizeOfArray=nums.size(),sumOfElements=0;
       
        for(int i=0;i<sizeOfArray;i++)
        {
            sumOfElements+=nums[i];
        }
        if(sumOfElements%2!=0 || sizeOfArray<2 ) return false;
        sumOfElements=sumOfElements/2;
        vector<vector<bool>> dp(sizeOfArray,vector<bool>(sumOfElements+2,false));
        if(nums[0]<=sumOfElements)
        dp[0][nums[0]]=true;
        for(int index=1;index<sizeOfArray;index++)
        {
            for(int j=0;j<=sumOfElements;j++)
            {
                bool take=false,ntake=false;
                if(nums[index]<=j)
                take=dp[index-1][j-nums[index]];
                ntake=dp[index-1][j];
                dp[index][j]=take|ntake;
            }
        }
        return dp[sizeOfArray-1][sumOfElements];
    }
};