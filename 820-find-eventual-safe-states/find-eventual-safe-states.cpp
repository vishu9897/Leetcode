class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        vector<int> color(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(dfs(graph,color,i)) res.push_back(i);
        }
        return res;
    }       
    bool dfs(vector<vector<int>> &graph,vector<int> &color,int src)
    {
        if(color[src]>0)
         return color[src]==2;
        color[src]=1;
        for(auto x:graph[src])
        {
            if(color[x]==1 || !dfs(graph,color,x)) return false;
        }
        color[src]=2;
        return true;
    }

};