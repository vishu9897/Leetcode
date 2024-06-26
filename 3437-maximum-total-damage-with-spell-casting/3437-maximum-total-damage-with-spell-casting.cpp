class Solution {
public:
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
            take = (val * index) + dp[k];
    
            dp[i]=max(take,ntake);          
        }
        return dp[0];
        
    }
};