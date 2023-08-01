int mod=1e9+7;
class Solution {
public:
    int solve(int n,int x,vector<vector<int>> &dp,int num=1,long long sum=0)
    {
        if(n==sum) return 1;
        if(num > n) return 0;
        if(dp[sum][num]!=-1) return dp[sum][num];
        int take=0,ntake=0;
        long long power= pow(num,x);
        if(power<=n)
        {
        if((long long)sum + power <= (long long)n)
            take = solve(n,x,dp,num+1,sum+power)%mod;
        }
        ntake = solve(n,x,dp,num+1,sum)%mod;
        return dp[sum][num] = (take % mod + ntake % mod) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp (373,vector<int>(320,-1)); 
        return solve(n,x,dp);
    }
};