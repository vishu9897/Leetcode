class Solution {
public:
    int solve(vector<int> &cuts,int l,int r,vector<vector<int>> &dp)
    {
        int  mini=INT_MAX;
        if(dp[l][r]!=-1) return dp[l][r];
        if(l+1==r || l>=r) return 0;
        for(int k=l+1;k<r;k++)
        {
            // cout<<l<<" "<<k<<" "<<r<<endl;
            int cases = (cuts[r]-cuts[l]) + solve(cuts,l,k,dp) + solve(cuts,k,r,dp);
            // cout<<"cases "<<cases<<endl;
            mini=min(cases,mini);
        }
        
        return dp[l][r]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
       
        cuts.push_back(n);
        int s=cuts.size();
        vector<vector<int>> dp(s,vector<int>(s,0));
        
        for(int i=s-1;i>=0;i--){
            for(int j=0;j<s;j++)
            {
                int mini=INT_MAX;
                 if(i+1==j || i>=j) continue;
                for(int k=i+1;k<j;k++)
                {
                    // cout<<l<<" "<<k<<" "<<r<<endl;
                    int cases = (cuts[j]-cuts[i]) + dp[i][k] + dp[k][j];
                    // cout<<"cases "<<cases<<endl;
                    mini=min(cases,mini);
                }
                dp[i][j]=mini;   
            }
        }

        
        return dp[0][s-1];
    }
};