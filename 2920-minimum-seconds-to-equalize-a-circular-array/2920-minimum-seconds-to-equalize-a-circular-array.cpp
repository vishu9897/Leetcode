class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
    unordered_map<int, vector<int>> n_pos;
    for (int i = 0; i < nums.size(); ++i)
        n_pos[nums[i]].push_back(i);
    int res = INT_MAX;
    for (auto &[n, pos] : n_pos) {
        pos.push_back(pos[0] + nums.size());
        int steps = 0;
        for (int i = 1; i < pos.size(); ++i)
            steps = max(steps, (pos[i] - pos[i - 1]) / 2);
        res = min(res, steps);
    }
    return res;
}
};