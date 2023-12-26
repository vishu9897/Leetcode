class Solution {
public:
    long long getCost(vector<vector<pair<char,int>>>&g, int start, int end)
    {
        long long res= LONG_MAX;
        vector<long long> vis(26,LONG_MAX);
        vis[start]=0;
        queue<pair<int,long long>> q;
        q.push({start,0});
        while(q.size())
        {
            auto [node,cost] =q.front();q.pop();
            for(auto [n,c] : g[node])
            {
                if(cost+c >= vis[n]) continue;
                q.push({n,cost+c});
                vis[n]=cost+c;
                if(n==end) res=cost+c;
            }
        }
        return (res==LONG_MAX) ? -1 : res;

    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans=0;
        unordered_map<long long,long long> costMap;
        vector<vector<pair<char,int>>> g(26);
        for(int i=0;i<cost.size();i++)
            g[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        for(int i=0;i<source.size();i++)
        {
            if(source[i]==target[i]) continue;
            long long t=0, hs=(source[i]-'a')*100 +target[i]-'a';
            if(costMap.find(hs) != costMap.end()) t=costMap[hs];
            else{
                t=getCost(g,source[i]-'a',target[i]-'a');
                costMap[hs]=t;
            }
            if(t == -1) return -1;
            ans+=t;
        }
        return ans;
    }
};