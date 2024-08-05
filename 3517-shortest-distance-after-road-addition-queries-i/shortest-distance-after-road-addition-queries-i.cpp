
class Solution {
public:
int count=0;
    void bfs(unordered_map<int,vector<pair<int,int>>> &adj,vector<int> &dist,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(dist[i]!=INT_MAX)
            {
                for(auto y:adj[i])
                {
                    pair<int,int> p =y;
                    if(dist[i] + p.second < dist[p.first])
                    {
                        dist[p.first]=dist[i]+p.second;
                    }
                }
            }
        }
        
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int,vector<pair<int,int>>> adj;

        for(int i=1;i<n;i++)
        {
            adj[i-1].push_back({i,1});
        }
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        for(auto x:queries)
        {
            int node1=x[0];
            int node2=x[1];
            adj[node1].push_back({node2,1});
            bfs(adj,dist,n);
            res.push_back(dist[n-1]);
        }
        
        return res;
    }
};