typedef long long int ll;
ll dp[101][101][101];

class Solution{
vector<vector<int>> g;
vector<vector<ll>> pref;
int R, C;

ll Score (int col, int cur_len, int max_len) {
    if (max_len <= cur_len) return 0;
    
    return pref[max_len][col] - pref[cur_len][col];
}

ll MaxScore (bool is_bigger, int prev_len, int col) {
    if (col == C+1) {
        if (!is_bigger) return 0;
        return 0;
    }
    
    ll &ans = dp[is_bigger][prev_len][col];
    if (ans != -1) return ans;
    
    ans = 0;
    for (int len = 0; len <= C; len ++) {
        ll prv_col = is_bigger? 0 : Score (col-1, prev_len, len);
        ll cur_score = Score (col, len, prev_len);
        
        ll with_bigger = cur_score + prv_col + MaxScore (true, len, col+1);
        ll without_bigger = prv_col + MaxScore (false, len, col+1);
        
        ans = max (ans, max(without_bigger, with_bigger));
    }
    return ans;
}

    
public:
    long long maximumScore(vector<vector<int>>& _grid) {
        R = _grid.size();
        C = _grid[0].size();
        
        g.clear(), g.resize(R+1, vector<int>(C+1, 0));
        for (int r = 1; r <= R; r ++)
            for (int c = 1; c <= C; c ++)
                g[r][c] = _grid[r-1][c-1];
        
        pref.clear(), pref.resize(R+1, vector<ll>(C+1, 0));
        for (int c = 1; c <= C; c ++)
            for (int r = 1; r <= R; r ++)
                pref[r][c] = pref[r-1][c] + g[r][c];
        
        memset(dp, -1, sizeof(dp));
        
        return MaxScore(0, 0, 1);
    }
};
