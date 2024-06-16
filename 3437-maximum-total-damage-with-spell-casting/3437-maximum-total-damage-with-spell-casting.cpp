class Solution {
public:
    long long solve(vector<int> &p,int i,vector<long long> &dp)
    {
        if(i >= p.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long take=0,ntake= solve(p,i+1,dp);
        
            long long j=i,k;
            for(j=i;j<p.size();j++)
            { 
                if(p[j] != p[i]) break;
            }
            for(k=j;k<p.size();k++)
            {
                long long temp= p[i]+2;
                long long temp1=p[k];
                if(temp < temp1) break;
            }
            long long index= (j-i);
            long long val= p[i];
            take = (long long) ((index * val) + solve(p,k,dp));
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
        // for(auto x:vc)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // cout<<endl;
        vector<long long> dp(vc.size()+1,0);
        for(int i=vc.size()-1;i>=0;i--)
        {
            long long ntake=dp[i+1];
            long long take=0;
            long long j=i,k;
            
            for(k=i;k<vc.size();k++)
            {
                long long temp= vc[i].first + 2;
                long long temp1=vc[k].first;
                if(temp < temp1) break;
            }
            long long index= vc[i].second;
            long long val= vc[i].first;
            take = (long long)((index * val) + dp[k]);
    
            dp[i]=max(take,ntake);          
        }
       return dp[0];
        return solve(p,0,dp);
        
    }
};