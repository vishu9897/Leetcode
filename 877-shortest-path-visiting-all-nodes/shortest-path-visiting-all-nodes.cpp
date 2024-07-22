class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<pair<int,int>,int>> q;
        int maxMask= (1<<n) - 1;
        set<pair<int,int>> st;

        for(int i=0;i<n;i++)
        {
            int mask=1<<i;
            q.push({{i,0},mask});
            st.insert({i,mask});
        }

        while(!q.empty())
        {
            pair<pair<int,int>,int> front=q.front();
            q.pop();
            int node=front.first.first;
            int step=front.first.second;
            int mask=front.second;

            if(mask==maxMask) return step;

            for(auto x: graph[node])
            {
                int newMask = (1<<x) | mask;

                if(st.find({x,newMask})!=st.end()) continue;
                st.insert({x,newMask});
                q.push({{x,step+1},newMask});
            }
        }

        return 0;
    }
};