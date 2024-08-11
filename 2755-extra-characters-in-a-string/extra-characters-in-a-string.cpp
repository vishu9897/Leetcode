class Solution {
public:
    int solve(unordered_set<string> &dict,string s,int index,vector<int> &dp)
    {
        if(index >= s.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int res=solve(dict,s,index+1,dp) +1;
        for(int i=1; index+i<=s.size();i++)
        {
            string t=s.substr(index,i);
            if(dict.find(t)!=dict.end()) res=min(res,solve(dict,s,i+index,dp));
        }
        return dp[index]=res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        unordered_set<string> dict;
        vector<int> dp(n+1,-1);
        for(string se:dictionary) dict.insert(se);
        return solve(dict,s,0,dp);
    }
};