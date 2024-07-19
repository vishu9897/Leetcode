class Solution {
public:
    bool solve(vector<vector<int>> &graph,int x,vector<int> &vis,vector<int> &pathVis,vector<int> &check)
    {
        vis[x]=1;
        pathVis[x]=1;
        check[x]=0;
        for(auto ele: graph[x])
        {
            if(vis[ele]==0)
            {
                if(solve(graph,ele,vis,pathVis,check)==true) {
                    // check[x]=0;
                    return true;
                }
            }
            else if(pathVis[ele]){
                // check[x]=0;
                return true;
            } 
        }
        check[x]=1;
        pathVis[x]=0;

        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> vis(m,0);
        vector<int> pathVis(m,0);
        vector<int> check(m,0);

        vector<int> res;
        for(int i=0;i<m;i++)
        {
            if(vis[i]==0)
            {
                solve(graph,i,vis,pathVis,check);
            }
        }
        for(int i=0;i<check.size();i++)
        {
            if(check[i]==1) res.push_back(i);
        }
        return res;
    }
};