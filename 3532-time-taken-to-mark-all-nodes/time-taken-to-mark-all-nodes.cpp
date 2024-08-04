class Solution {
public:
    struct NodeInfo {
        int node;
        int cost;
        NodeInfo(int n = 0, int c = 0) : node(n), cost(c) {}
    };

    void dfs(int node, const vector<vector<int>>& adj, int parent, vector<pair<NodeInfo, NodeInfo>>& dp) {
        for (int child : adj[node]) {
            if (child == parent) continue;
            dfs(child, adj, node, dp);
            updateNodeInfo(dp[node], {child, calculateCost(child, dp[child].first.cost)});
        }
    }

    void dfs2(int node, const vector<vector<int>>& adj, int parent, 
              const vector<pair<NodeInfo, NodeInfo>>& dp, vector<pair<NodeInfo, NodeInfo>>& dp2) {
        if (parent != -1) {
            int parentCost = (dp2[parent].first.node == node) ? dp2[parent].second.cost : dp2[parent].first.cost;
            int costFromParent = calculateCost(parent, parentCost);
            dp2[node] = {{parent, costFromParent}, {0, 0}};
            
            for (int child : adj[node]) {
                if (child == parent) continue;
                updateNodeInfo(dp2[node], {child, calculateCost(child, dp[child].first.cost)});
            }
        }

        for (int child : adj[node]) {
            if (child == parent) continue;
            dfs2(child, adj, node, dp, dp2);
        }
    }

    void updateNodeInfo(pair<NodeInfo, NodeInfo>& info, const NodeInfo& newInfo) {
        if (newInfo.cost > info.first.cost) {
            info.second = info.first;
            info.first = newInfo;
        } else if (newInfo.cost > info.second.cost) {
            info.second = newInfo;
        }
    }

    int calculateCost(int node, int childCost) {
        return 1 + childCost + (node % 2 == 0);
    }

    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<pair<NodeInfo, NodeInfo>> dp(n), dp2(n);
        dfs(0, adj, -1, dp);
        dp2 = dp;
        dfs2(0, adj, -1, dp, dp2);

        vector<int> answer;
        for (const auto& info : dp2) {
            answer.push_back(info.first.cost);
        }
        return answer;
    }
};