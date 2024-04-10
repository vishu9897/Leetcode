class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        vector<pair<int,int>> adj[n];
        queue<pair<int,pair<int,int>>> q;
        for(auto x: flights)
        {
            int u= x[0];
            int v= x[1];
            int d= x[2];
            adj[u].push_back({v,d});
        }
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty())
        {
            auto front=q.front();
            q.pop();
            int stop= front.first;
            int node= front.second.first;
            int dis= front.second.second;
            
            if(stop>k) continue;

            for(auto x: adj[node])
            {
                int v=x.first;
                int tempDis= x.second;
                if(dis + tempDis < dist[v])
                {
                    dist[v]=dis+tempDis;
                    q.push({stop+1,{v,dist[v]}});
                }
            }
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};