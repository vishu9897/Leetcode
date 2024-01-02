class Solution {
public:
    bool solve(string &s,string &p,int index1,int index2,vector<vector<int>> &dp)
    {
        if(index1<0 && index2<0) return true;
        if(index2<0 && index1>=0) return false;
        if(index2>=0 && index1<0){
            for(int i=index2;i>=0;i--){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1]==p[index2] || p[index2]=='?') return dp[index1][index2] = solve(s,p,index1-1,index2-1,dp);
        if(p[index2]=='*') return dp[index1][index2] = solve(s,p,index1,index2-1,dp) | solve(s,p,index1-1,index2,dp);
        return dp[index1][index2] = false;
    }
    bool isMatch(string s, string p) {
        int n1=s.size(),n2=p.size();
        vector<vector<int>> dp(n1+2,vector<int>(n2+4,-1));
        return solve(s,p,n1-1,n2-1,dp);
    }
};