
class Solution {
public:
    int solve(vector<int> &num,int index,int n,int x,vector<int> &dp)
    {
        if(index>=n)
        {
            return x;
        }
        if(dp[x]!=-1) return dp[x];
        
        int ans=x;
        for(int i=index;i<n;i++)
        {
            if(x < num[i] && x+num[i] <= 4000) ans= max(ans,solve(num,i+1,n,x+num[i],dp));
        }
        return dp[x]=ans;
        
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int n=rewardValues.size();
        vector<int> dp(7005,-1);
        
        return solve(rewardValues,0,n,0,dp);
    }
};