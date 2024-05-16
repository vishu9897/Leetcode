int val[14][16384], dp[14][16384];
class Solution {
public:
int dfs(unsigned int mask, int p, vector<int>& nums) {
    if (popcount(mask) == nums.size())
        return abs(p - nums[0]);
    if (dp[p][mask] < 0) {
        dp[p][mask] = INT_MAX;
        for (int n = 1; n < nums.size(); ++n)
            if (((1 << n) & mask) == 0) {
                int res_n = abs(p - nums[n]) + dfs(mask + (1 << n), n, nums);
                if (res_n < dp[p][mask]) {
                    dp[p][mask] = res_n;
                    val[p][mask] = n;    
                }
            }
    }
    return dp[p][mask];
}
vector<int> findPermutation(vector<int>& nums) {
    memset(dp, -1, sizeof(dp));
    dfs(1, 0, nums);
    vector<int> res{0};
    for (uint mask = 1; popcount(mask) < nums.size(); mask += (1 << res.back()))
        res.push_back(val[res.back()][mask]);
    return res;
}
};