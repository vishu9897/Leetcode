class Solution {
private:
    
    bool frogJump(unordered_map<long long,int> &mp,int current,int k,int last,vector<vector<int>> &dp,vector<int>& stones)
    {
        if(current == last) return true;
        if(dp[current][k]!=-1) return dp[current][k];
        bool take= false;
        if(mp[stones[current]+k] && current < mp[stones[current]+k]) take = frogJump(mp,mp[stones[current]+k],k,last,dp,stones);
        if(mp[stones[current]+k+1] && current < mp[stones[current]+k+1]) take = take | frogJump(mp,mp[stones[current]+k+1],k+1,last,dp,stones);
        if(mp[stones[current]+k-1] && current < mp[stones[current]+k-1]) take =  take |frogJump(mp,mp[stones[current]+k-1],k-1,last,dp,stones);
        return dp[current][k]=take;
    }
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<long long,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[stones[i]]=i;
        }
        if(stones[1]-stones[0] != 1) return false;
        
        vector<vector<int>> dp(2004,vector<int>(2005,-1));
        
        return frogJump(mp,1,1,n-1,dp,stones);
    }
};