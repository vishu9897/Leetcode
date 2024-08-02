// Top-Down
class Solution {
    // int dp[101][101][35];
    public:
    int max = 99999999;
    int K;
    
    int mergeStones(vector<int> &stones, int k) {
        K = k;
        int len = stones.size();
        if ((len - 1) % (K - 1) != 0) {
            return -1;
        }
        vector<vector<vector<int>>> dp(len+1 , vector<vector<int>> (len+1,vector<int>(K+1,-1)));
        // dp = new int[len + 1][len + 1][K + 1];
        vector<int> prefixSum(len+1);
        
        int i;
        for (i = 1; i <= len; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i - 1];
        }
        
        return getResult(prefixSum, 1, len, 1,dp);
    }
    
    int getResult(vector<int>  &prefixSum, int left, int right, int piles,vector<vector<vector<int>>> &dp) {
        if (dp[left][right][piles] != -1) {
            return dp[left][right][piles];
        }
        int res = max;
        int t;
        if (left == right) {
            res = (piles == 1) ? 0 : max;
        }
        else {
            if (piles == 1) {
                res = getResult(prefixSum, left, right, K,dp) + prefixSum[right] - prefixSum[left - 1]; 
            }
            else {
                for (t = left; t < right; t++) {
                    res = min(res, getResult(prefixSum, left, t, piles - 1,dp) + getResult(prefixSum, t + 1, right, 1,dp));
                }
            }
        }
        dp[left][right][piles] = res;
        return res;
    }
};