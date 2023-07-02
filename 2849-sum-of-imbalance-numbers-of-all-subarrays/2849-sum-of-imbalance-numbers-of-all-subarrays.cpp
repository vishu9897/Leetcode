class Solution {
public:
        int sumImbalanceNumbers(vector<int>& A) {
        int res = 0, n = A.size();
        vector<int> left(n), seen(n + 10, -1);
        for (int i = 0; i < n; i++) {
            left[i] = max(seen[A[i] + 1], seen[A[i]]);
            seen[A[i]] = i;
        }
        seen.assign(n + 10, n);
        for (int i = n - 1; i >= 0; i--) {
            seen[A[i]] = i;
            res += (i - left[i]) * (seen[A[i] + 1] - i);
        }
        return res - n * (n + 1) / 2;
    }
};