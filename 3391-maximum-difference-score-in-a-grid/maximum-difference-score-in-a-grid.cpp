class Solution {
public:
        int maxScore(vector<vector<int>>& A) {
        int res = -1e6, m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int pre = min(i > 0 ? A[i - 1][j] : 1e6, j > 0 ? A[i][j - 1] : 1e6);
                res = max(res, A[i][j] - pre);
                A[i][j] = min(A[i][j], pre);
            }
        }
        return res;
    }
};