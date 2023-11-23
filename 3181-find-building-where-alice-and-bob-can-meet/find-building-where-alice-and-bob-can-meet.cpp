class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> res(queries.size(),-1);
        vector<vector<vector<int>>> q(heights.size());
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        for(int i=0;i<queries.size();i++)
        {
            int ind1= queries[i][0]<=queries[i][1] ? queries[i][0] : queries[i][1] ,ind2= queries[i][0]<=queries[i][1] ? queries[i][1] : queries[i][0];
            if(ind1==ind2) res[i]=ind1;
            else if(heights[ind1] < heights[ind2]) res[i]=ind2;
            else q[ind2].push_back({max(heights[ind1],heights[ind2]),i});
        }
        for(int i=0;i<heights.size();i++)
        {
            while(!pq.empty() && pq.top()[0]< heights[i])
            {
                res[pq.top()[1]]=i;
                pq.pop();
            }
            for(auto x:q[i])
            {
                pq.push(x);
            }   
        }
        return res;
    }
};