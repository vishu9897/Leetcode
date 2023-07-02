class Solution {
public:
    int sumImbalanceNumbers(vector<int>& A) {
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> s = {A[i]};
            int cur = 0;
            for (int j = i + 1; j < n; ++j) {
                cur += s.count(A[j]) ? 0 : 1 - s.count(A[j] + 1) - s.count(A[j] - 1);
                s.insert(A[j]);
                res += cur;
            }
        }
        return res;
    }
};