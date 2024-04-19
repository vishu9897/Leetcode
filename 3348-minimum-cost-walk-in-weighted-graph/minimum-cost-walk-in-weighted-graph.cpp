class Solution {
public:
    int findParent(vector<int> &parent, int u)
    {
        if(parent[u]==u) return u;
        return parent[u]=findParent(parent,parent[u]);
    }
    void unionFind(int u,int v,int w, vector<int> &parent, vector<pair<int,int>> &rank)
    {
        int pu= findParent(parent,u);
        int pv= findParent(parent,v);
        if(pu!=pv){
            if(rank[pu].first < rank[pv].first){
                parent[pu]=pv;
                rank[pv].second= rank[pv].second & w & rank[pu].second;
            }
            else if(rank[pu].first > rank[pv].first){
                parent[pv]=pu;
                rank[pu].second= rank[pv].second & w & rank[pu].second;
            }
            else{
            parent[pu]=pv;
            rank[pv].second= rank[pv].second & w & rank[pu].second;
            rank[pv].first=rank[pv].first+1;
            }
        }
        else{
            rank[pv].second= rank[pv].second & w;
        }


    }
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query) {
        vector<int> ans(query.size());
        vector<int> parent(n);
        vector<pair<int,int>> rank(n,{0,INT_MAX});
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v= edges[i][1];
            int w= edges[i][2];
            unionFind(u,v,w,parent,rank);
        }   
        for(int i=0;i<query.size();i++)
        {
            int u=query[i][0];
            int v=query[i][1];
            
            int pu= findParent(parent,u);
            int pv= findParent(parent,v);
            if(pu!=pv) ans[i]=-1;
            else ans[i]=rank[pu].second;
        }
        return ans;
    }
};

//TC : O(E* LOG V)
//SC : O(N) + O(N) + O(QuerySize)