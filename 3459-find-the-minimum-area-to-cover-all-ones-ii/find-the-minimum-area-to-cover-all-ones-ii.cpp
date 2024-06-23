class Solution {
public:
    int min1(vector<vector<int>>& g, const array<int, 4> &c) { // bottom, left, top, right
    int a[4] = {INT_MAX, INT_MAX, 0, 0 }; 
    for (int i = c[0]; i < c[2]; ++i)
        for (int j = c[1]; j < c[3]; ++j)
            if (g[i][j]) {
                a[0] = min(a[0], i);
                a[1] = min(a[1], j);
                a[2] = max(a[2], i);
                a[3] = max(a[3], j);                    
            }
    return a[0] == INT_MAX ? 0 : (a[2] - a[0] + 1) * (a[3] - a[1] + 1);
}
int min2(vector<vector<int>>& g, const array<int, 4> &c) {
    int res = INT_MAX;
    for (int i = c[0] + 1; i <= c[2]; ++i)
        res = min(res, min1(g, {c[0], c[1], i, c[3]}) + min1(g, {i, c[1], c[2], c[3]}));
    for (int j = c[1] + 1; j <= c[3]; ++j)
        res = min(res, min1(g, {c[0], c[1], c[2], j}) + min1(g, {c[0], j, c[2], c[3]}));
    return res;
}    
int minimumSum(vector<vector<int>>& g) {
    int res = INT_MAX, m = g.size(), n = g[0].size();
    for (int i = 1; i <= m; ++i) {
        array<int, 4> t = {0, 0, i, n}, b = {i, 0, m, n};
        res = min({res, min1(g, t) + min2(g, b), min1(g, b) + min2(g, t)});
    }
    for (int j = 1; j <= n; ++j) {
        array<int, 4> l = {0, 0, m, j}, r = {0, j, m, n};
        res = min({res, min1(g, l) + min2(g, r), min1(g, r) + min2(g, l) });
    }    
    return res;
}
};