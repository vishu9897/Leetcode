class Solution {
private:
	int solve(string &text1,string &text2,int index1,int index2,vector<vector<int>>&dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
		if(text1[index1]==text2[index2]) return dp[index1][index2] = 1+ solve(text1,text2,index1-1,index2-1,dp);
		return dp[index1][index2] = max(solve(text1,text2,index1,index2-1,dp),solve(text1,text2,index1-1,index2,dp));
}


public:
    int longestCommonSubsequence(string text1, string text2) {
    	int n1=text1.size();
	    int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
	return solve(text1,text2,n1-1,n2-1,dp);
    }
};

