class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;
        vector<vector<int>> res;
        for(int i=0;i<points.size();i++)
        {
            int pt1=points[i][0];
            int pt2=points[i][1];
            int finalSum=(pt1*pt1)+(pt2*pt2);
            pq.push({finalSum,points[i]});
        }

        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};