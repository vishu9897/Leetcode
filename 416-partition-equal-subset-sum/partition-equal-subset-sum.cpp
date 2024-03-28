class Solution {
public:
    bool checkEqualSubset(vector<int> &nums,int index,int sumOfElements,vector<vector<int>> &dp)
    {
        if(index<0) return sumOfElements==0 ? true : false;
        if(dp[index][sumOfElements]!=-1) return dp[index][sumOfElements]; 
        bool take=false,ntake=false;
        if(nums[index]<=sumOfElements) take=checkEqualSubset(nums,index-1,sumOfElements-nums[index],dp);
        ntake=checkEqualSubset(nums,index-1,sumOfElements,dp);
        return dp[index][sumOfElements]= take|ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sizeOfArray=nums.size(),sumOfElements=0;
       
        for(int i=0;i<sizeOfArray;i++)
        {
            sumOfElements+=nums[i];
        }
        if(sumOfElements%2!=0) return false;
        sumOfElements=sumOfElements/2;
        vector<vector<int>> dp(sizeOfArray,vector<int>(sumOfElements+2,-1));
        return checkEqualSubset(nums,sizeOfArray-1,sumOfElements,dp);
    }
};