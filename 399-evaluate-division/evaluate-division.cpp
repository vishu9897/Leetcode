class Solution {
public:
    bool dfs(unordered_map<string,vector<pair<string,double>>> &adj,string u,string &v,unordered_map<string,int> &visited,double &val,double temp=1){
        visited[u]=1;
        if(u==v){
            val=temp;
            return true;
        }
        for(auto x: adj[u])
        {
            string x1=x.first;
            double dist=x.second;
            
            if(visited[x1]==0)
            {
                if(dfs(adj,x1,v,visited,val,temp*dist)) return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string,vector<pair<string,double>>> adj;
        unordered_map<string,int> visited;
        
        for(int i=0;i<equations.size();i++)
        {
            string u= equations[i][0];
            string v= equations[i][1];
            visited[u]=0;
            visited[v]=0;
            adj[u].push_back({v,values[i]});
            adj[v].push_back({u,1/values[i]});
        }

        for(int i=0;i<queries.size();i++)
        {
            string u=queries[i][0];
            string v=queries[i][1];
            if(adj.find(u)==adj.end() || adj.find(v)==adj.end()){
                res.push_back(-1);
                continue;
            }
            double val=1.0;
            
            val = dfs(adj,u,v,visited,val) ? val : -1;
            for(auto x: visited)
            {
                visited[x.first]=0;
            }
            res.push_back(val);

        }
        return res;
    }
};