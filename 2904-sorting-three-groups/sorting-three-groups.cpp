class Solution {
public:
        int minimumOperations(vector<int>& A) {
        int n = A.size(), res = n;
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int cur = 0;
                for (int k = 0; k < n; k++) {
                    if (k < i) {
                        cur += A[k] != 1;
                    } else if (k < j) {
                        cur += A[k] != 2;
                    } else {
                        cur += A[k] != 3;
                    }
                }
                res = min(res, cur);
            }
        }
        return res;
    }
};