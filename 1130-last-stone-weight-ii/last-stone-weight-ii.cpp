class Solution {
private:
	int solve(vector<int> &stones,int n,int index,int sum,vector<vector<int>> &dp){
		if(index==n){
			return sum>=0 ? sum : INT_MAX;	
		}
        if(dp[index][sum+5000] != -1) return dp[index][sum + 5000];
		int pos=INT_MAX,neg=INT_MAX;
		pos= solve(stones,n,index+1,sum + stones[index],dp);
		neg= solve(stones,n,index+1,sum - stones[index],dp);
		return dp[index][sum+5000] = min(pos,neg);
	}
public:
    int lastStoneWeightII(vector<int>& stones)
    { 
        int n=stones.size();
	 	if(n==1) return stones[0];
        vector<vector<int>> dp(n,vector<int>(9000,-1));
		return solve(stones,n,0,0,dp);
    }
};

