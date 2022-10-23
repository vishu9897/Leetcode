class Solution {
    struct comp {
        inline bool operator() (int& a, int& b) const {
            return (a & 1) == (b & 1) ? a < b : a & 1;
        }
    };
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(begin(nums), end(nums), comp());
        sort(begin(target), end(target), comp());
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) 
            res += max(0, nums[i] - target[i]) / 2;
        return res;
    }
};