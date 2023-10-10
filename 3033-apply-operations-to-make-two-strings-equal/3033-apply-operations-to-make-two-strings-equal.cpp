class Solution {
public:
    int dp[501][501];
    int solve(int left,int right,vector<int> &a,int cost)
    {
        if(left>=right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        return dp[left][right]= min({min(cost,a[left+1]-a[left]) + solve(left+2,right,a,cost) , min(cost,a[right]-a[left]) + solve(left+1,right-1,a,cost) , min(cost,a[right]-a[right-1]) + solve(left,right-2,a,cost) });
    }
    int minOperations(string s1, string s2, int x) {
        vector<int> a;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i]) a.push_back(i);
        }
        if(a.size()%2) return -1;
        if(a.size()==0) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,a.size()-1,a,x);
    }
};