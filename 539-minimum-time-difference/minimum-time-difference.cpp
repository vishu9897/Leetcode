class Solution {
public:
    int time_diff(const string& t1, const string& t2) {
        int t1_hour = stoi(t1.substr(0, 2));
        int t2_hour = stoi(t2.substr(0, 2));
        int t1_min = stoi(t1.substr(3));
        int t2_min = stoi(t2.substr(3));
        
        return 60 * t2_hour + t2_min - 60 * t1_hour - t1_min;
    }
    
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        
        int curr_min = INT_MAX;
        for (int i = 0; i < timePoints.size() - 1; i++) {
            int curr_diff = time_diff(timePoints[i], timePoints[i + 1]);
            if (curr_diff < curr_min) curr_min = curr_diff;
        }
        int last_cand = 24 * 60 - time_diff(timePoints[0], timePoints[timePoints.size() - 1]);
        if (last_cand < curr_min) curr_min = last_cand;
        
        return curr_min;
    }
};