class Solution {
private:
    int dp[90000][16];
    int specialPerm(int index,int mask,int n)
    {
        if(index>=n){
            return 1;
        }
        if(dp[mask][index]!=-1) return dp[mask][index];
        int totalWays=0;
        for(int i=1;i<=n;i++)
        {
            if((((1<<i) & mask) ==0) && ((i%(index+1) ==0) || ((index+1)%i==0)))
            {
                mask=mask | (1<<i);
                totalWays+=specialPerm(index+1,mask,n);
                mask= mask ^ (1<<i);
            }
        }
        return dp[mask][index]=totalWays;
    }
public:
    int countArrangement(int n) {
        int mask=0;
        
        memset(dp,-1,sizeof(dp));
        return specialPerm(0,mask,n);
    }
};