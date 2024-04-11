class Solution {
public:
    int findParent(vector<int> &parent,int u)
    {
        if(parent[u]==u) return u;
        return parent[u]= findParent(parent,parent[u]);
    }
    void unionBySize(vector<int> &size,vector<int> &parent,int u,int v)
    {
        int pu= findParent(parent,u);
        int pv= findParent(parent,v);

        if(pu==pv) return;

        if(size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
        else
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
    void unionByRank(vector<int> &rank,vector<int> &parent,int u,int v)
    {
        int pu= findParent(parent,u);
        int pv= findParent(parent,v);

        if(pu==pv) return;

        if(rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[v]=u;
            rank[pu]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        vector<int> size(n,1);
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    unionBySize(size,parent,i,j);     
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(parent[i]==i) 
            {
                cnt++;
            }
        }
        return cnt;
    }
};