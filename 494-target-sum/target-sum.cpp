class Solution{
private:
    int solve(vector<int>&nums,int target,int index,vector<vector<int>> &dp)
	{
		if(index<0) return target==0 ? 1 : 0;
		if(dp[index][target]!=-1) return dp[index][target];
		int take=0,ntake;
		if(target-nums[index]>=0){
			take= solve(nums,target-nums[index],index-1,dp);
		}
		ntake= solve(nums,target,index-1,dp);
		return dp[index][target]= take+ntake;
	}

public:	
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
		for(auto x:nums){
			sum+=x;
		}
        if(sum<target) return 0;
        sum=sum-target;
        if(sum%2==1) return 0;
		sum=sum/2;
        cout<<sum<<endl;
		vector<vector<int>> dp(nums.size(),vector<int>(sum+2,-1));
		return solve(nums,sum,nums.size()-1,dp);
    }
    
};

