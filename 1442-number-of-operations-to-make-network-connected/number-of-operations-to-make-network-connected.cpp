
class Solution {
public:
    int findParent(vector<int>& parent,int node)
    {
        if(parent[node]==node) return node;
        return parent[node]= findParent(parent,parent[node]);
    }
    void unionBySize(vector<int> &parent,vector<int> &size,int u, int v,int &cnt)
    {
        int pu= findParent(parent,u);
        int pv= findParent(parent,v);
        if(pu==pv) 
        {
            cnt++;
            return;
        }
        if(size[pu] < size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> size(n,1);
        int cnt=0;
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<connections.size();i++)
        {
            unionBySize(parent,size,connections[i][0],connections[i][1],cnt);    
        } 
        int noOfDisconnectedComponent=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i) noOfDisconnectedComponent++;
        }  
        return noOfDisconnectedComponent-1<=cnt ? noOfDisconnectedComponent-1 :-1;
    }
};