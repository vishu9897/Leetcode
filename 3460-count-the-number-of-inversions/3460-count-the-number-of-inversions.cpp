class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,int n,unordered_map<int,int> &mp,int cnt,vector<vector<int>> &dp)
    {
        if(ind>=n-1) return 1;
        if(dp[ind][cnt]!=-1) return dp[ind][cnt];
        int sub=0;
        for(int i=0;i<=ind+1;i++)
        {
            // cout<<ind+1<<" "<<cnt+i<<endl;
            if(mp.find(ind+1)!=mp.end() && mp[ind+1] != cnt+i){
                // cout<<mp[ind+1]<<" ";
                // cout<<"yes"<<endl;
                continue;
            } 
            if(cnt+i >400) continue;
            // cout<<"--"<<endl;
            sub = (sub + solve(ind+1,n,mp,cnt+i,dp))%mod;
        }
        return dp[ind][cnt]= sub;
    }
    int numberOfPermutations(int n, vector<vector<int>>& r) {
        unordered_map<int,int> mp;
        vector<vector<int>> dp(302,vector<int> (402,-1));
        for(int i=0;i<r.size();i++)
        {
            mp[r[i][0]]=r[i][1];
        }
        if(mp.find(0)!=mp.end() && mp[0]!=0) return 0;
        return solve(0,n,mp,0,dp);
    }
};