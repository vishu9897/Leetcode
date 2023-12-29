class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans;
        vector<int> curr(amount+2,INT_MAX), prev(amount+2,INT_MAX);
        // vector<vector<int>> dp(n+3,vector<int>(amount+2,INT_MAX));
        for(int i=0;i<n;i++) prev[0]=0;
        for(int i=0;i<=amount;i++) if(i%coins[0]==0) prev[i]=i/coins[0];
        curr=prev;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                long long take=INT_MAX,ntake= prev[j];
                if(j>=coins[i]) take=(long long) 1+ curr[j-coins[i]];
                curr[j]=min(take,ntake);
            }
            prev=curr;
        }
        ans=curr[amount];
        return ans>=INT_MAX ? -1 : ans;
    }
};