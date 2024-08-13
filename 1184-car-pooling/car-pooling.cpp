class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> line;
        for(int i=0;i<trips.size();i++)
        {
            line[trips[i][1]] += trips[i][0];
            line[trips[i][2]] -= trips[i][0];
        }
        int cnt=0;
        for(auto x: line)
        {
            cnt+=x.second;
            if(cnt > capacity) return false;
        }
        return true;
    }
};