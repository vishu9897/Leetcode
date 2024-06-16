class Solution {
public:
    long long solve(vector<pair<int,int>> &vc,int i,vector<long long> &dp)
    {
        if(i >= vc.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long take=0,ntake= solve(vc,i+1,dp);
        
            int k;
            for(k=i;k<vc.size();k++)
            {
                long long temp= vc[i].first+2;
                long long temp1=vc[k].first;
                if(temp < temp1) break;
            }
            long long index= vc[i].second;
            long long val= vc[i].first;
            take = index * val + solve(vc,k,dp);
        return dp[i]=max(take , ntake);
    }
    long long maximumTotalDamage(vector<int>& p) {
        map<int,int> mp;
        vector<pair<int,int>> vc;
        for(auto x: p)
        {
            mp[x]++;
        }
        for(auto x: mp)
        {
           vc.push_back({x.first,x.second}); 
        }
        vector<long long> dp(vc.size()+1,-1);
        return solve(vc,0,dp);
        
    }
};