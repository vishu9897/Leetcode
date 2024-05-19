class Solution {
private:
    int findParent(int u,vector<int> &parent)
    {
        if(u==parent[u])
        {
            return u;
        }
        return parent[u]=findParent(parent[u],parent);
    }
    void findUnion(int u,int v,vector<int> &parent,vector<int> &rank)
    {
        int up=findParent(u,parent);
        int uv= findParent(v,parent);

        if(up==uv) return;

        if(rank[up] < rank[uv]) parent[up]=uv;
        else if(rank[up] > rank[uv]) parent[uv]=up;
        else
        {
            parent[uv]=up;
            rank[up]++;
        }
    }
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n),rank(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
        }
        vector<vector<string>> res;
        unordered_map<string,int> mp;
        cout<<"1st step"<<endl;
        for(int i=0;i<accounts.size();i++){
            vector<string> acc= accounts[i];
            for(int j=1;j<acc.size();j++){
                string s=acc[j];
                if(mp.find(s)!=mp.end())
                {
                    findUnion(mp[s],i,parent,rank);
                }
                else mp[s]=i;
            }
        }
            vector<string> mergedList[n];
            for(auto it: mp)
            {
                int node=findParent(it.second,parent);
                string mail=it.first;

                mergedList[node].push_back(mail);
            }
            for(int i=0;i<n;i++)
            {
                if(mergedList[i].size()>0)
                {
                    sort(mergedList[i].begin(),mergedList[i].end());
                    mergedList[i].insert(mergedList[i].begin(),accounts[i][0]);
                    res.push_back(mergedList[i]);
                }
                
            }
        return res;
        
    }
};