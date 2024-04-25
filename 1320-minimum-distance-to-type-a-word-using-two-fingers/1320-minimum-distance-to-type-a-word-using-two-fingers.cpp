class Solution {
public:
    int dist(char ch1,char ch2)
    {
        if(ch2=='a') return 0;
        int row1= (ch1-'A')/6;
        int col1= (ch1-'A')%6;
        int row2= (ch2-'A')/6;
        int col2= (ch2-'A')%6;
        
        return abs(row2-row1)+abs(col2-col1);
    }
    int solve(string &word,char fingerFirstch,char fingerSecondch,int index, vector<vector<vector<int>>> &dp)
    {
        if(index>=word.size()) return 0;
        if(dp[index][fingerFirstch-'A'][fingerSecondch-'A']!=-1) return dp[index][fingerFirstch-'A'][fingerSecondch-'A'];
        int distFirst= dist(word[index],fingerFirstch);
        int distSecond= dist(word[index],fingerSecondch);
        return dp[index][fingerFirstch-'A'][fingerSecondch-'A'] = min(distFirst + solve(word,word[index],fingerSecondch,index+1,dp),distSecond + solve(word,fingerFirstch,word[index],index+1,dp));
    }
    int minimumDistance(string word) {
        vector<vector<vector<int>>> dp(word.size()+2,vector<vector<int>>(127,vector<int>(127,-1)));
        return solve(word,'a','a',0,dp);
    }
};