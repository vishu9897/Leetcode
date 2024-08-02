class Solution {
public:
    bool solve(string s,string p,int i,int j,vector<vector<int>> &dp)
    {
        int n1=s.size();
        int n2=p.size();

        if(i>=n1 && j>=n2) return true;
        if(i>=n1 && j<n2) {
            for(int k=j;k<n2;k++)
            {
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(j>=n2 && i<n1) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j]=solve(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='*') return dp[i][j]=solve(s,p,i+1,j,dp) | solve(s,p,i,j+1,dp);
        return dp[i][j]=false;
    }   
    bool isMatch(string s, string p) {
        int n1=s.size(),n2=p.size();
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,false));
        for(int j=n2;j>=1;j--)
        {
            if(p[j-1]!='*') break;
            dp[n1][j-1]=true;
        }
        dp[n1][n2]=true;
        // for(int i=0;i<=n1;i++)
        // {
        //     for(int j=0;j<=n2;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(s[i]==p[j] || p[j]=='?')
                {
                    dp[i][j]= dp[i+1][j+1];
                }
                else if(p[j]=='*')  dp[i][j]=dp[i+1][j] | dp[i][j+1];
                else dp[i][j]=false;   
            }
        }
        return dp[0][0];   
    }
};