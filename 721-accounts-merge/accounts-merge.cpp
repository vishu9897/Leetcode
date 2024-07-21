class Solution {
public:
    int findParent(int u, vector<int> &parent)
    {
        if(parent[u]==u) return u;

        return parent[u]= findParent(parent[u],parent);
    }
    void unionThem(int u,int v,vector<int> &parent,vector<int> &rank)
    {
        int pu=findParent(u,parent);
        int pv=findParent(v,parent);

        if(pu==pv) return;

        if(rank[pu] < rank[pv]) parent[pu]=pv;
        else if(rank[pu] > rank[pv]) parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        vector<int> parent(accounts.size());
        vector<int> rank(accounts.size(),0);
        for(int i=0;i<accounts.size();i++)
        {
            parent[i]=i;
        }
        int n=accounts.size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++){
                string s=accounts[i][j];

                if(mp.find(s)!=mp.end())
                {
                    int u= i;
                    int v= mp[s];
                    unionThem(u,v,parent,rank);
                }
                else{
                    mp[s]=i;
                }

            }
        }
        vector<vector<string>>  res;
        vector<vector<string>> vc(accounts.size());
        for(auto x: mp)
        {
            string s=x.first;
            int node=x.second;  

            node=findParent(node,parent);
            vc[node].push_back(s);
        }
        for(int i=0;i<vc.size();i++)
        {
            if(vc[i].size()>0){
                sort(vc[i].begin(),vc[i].end());
                vc[i].insert(vc[i].begin(),accounts[i][0]);
                res.push_back(vc[i]);

            }
        }

        return res;

    }
};