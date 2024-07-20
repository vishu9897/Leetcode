class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
									 
        unordered_map<int,vector<pair<int,int>>> adj;

        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int d=flights[i][2];
            adj[u].push_back({v,d});
        }

        queue<pair<int,pair<int,int>>> pq;
        dist[src]=0;
        pq.push({0,{src,0}});

        while(!pq.empty())
        {
           pair<int,pair<int,int>> front= pq.front();
           pq.pop();
           int stop= front.first;
           int v= front.second.first;
           int d=front.second.second;
			
           if(stop > k) continue;
            // if(v==dest) return 
           for(auto x: adj[v])
           {
                int node=x.first;
                int di=x.second;

								  
			 
							  
									  
                if(di+d < dist[node])
                {
                    dist[node]=di + d;
                    pq.push({stop+1,{node,dist[node]}});
                }
           }
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];
						 
    }
};