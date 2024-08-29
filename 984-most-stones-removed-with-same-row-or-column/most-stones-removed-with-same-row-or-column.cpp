class DisjointSet{
    vector<int> parent,rank,size;
    public:
        DisjointSet(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1,0);
            size.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        int findPar(int node){
            if(node== parent[node]) return node;
            return parent[node]=findPar(parent[node]);
        }
        void unionByRank(int u,int v)
        {
            int ur=findPar(u);
            int vr=findPar(v);
            if(ur==vr) return;
            if(rank[ur] < rank[vr]) parent[ur]=vr;
            else if(rank[ur] > rank[vr]) parent[vr]=ur;
            else {
                parent[ur]=vr;
                rank[vr]++;
            }
        }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0,maxCol=0;
        for(auto x:stones)
        {
            maxRow=max(maxRow,x[0]);
            maxCol=max(maxCol,x[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> mp;
        for(auto x:stones)
        {
            int nodeRow=x[0];
            int nodeCol=x[1] + maxRow +1;
            ds.unionByRank(nodeRow,nodeCol);
            mp[nodeRow]=1;
            mp[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:mp)
        {
            if(ds.findPar(it.first)==it.first)
            {
                cnt++;
            }
        }   
        return stones.size()-cnt;

    }
};