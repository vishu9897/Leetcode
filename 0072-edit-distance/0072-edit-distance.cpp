class Solution {
public:
    int solve(string &word1,string &word2,int index1,int index2,vector<vector<int>> &dp)
    {
        if(index1<0) return index2+1;
        if(index2<0) return index1+1;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(word1[index1]==word2[index2]) return 0 + solve(word1,word2,index1-1,index2-1,dp);
        return dp[index1][index2] = 1+min(min(solve(word1,word2,index1,index2-1,dp) ,solve(word1,word2,index1-1,index2,dp)),solve(word1,word2,index1-1,index2-1,dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
     return solve(word1,word2,word1.size()-1,word2.size()-1,dp);   
    }
};