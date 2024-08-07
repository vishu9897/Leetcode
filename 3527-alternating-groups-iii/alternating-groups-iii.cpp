#define pii pair<int, int>
#define F first
#define S second
 
struct SegTree {
public:
 
    SegTree (int _n) : n (_n) {
        tree_val.resize(4*n, 0);
        tree_cnt.resize(4*n, 0);
    }
    
    int query_sum (int x) {
        return query_sum (x, n-1, 0, n-1, 0);
    }
    
    int query_cnt (int x) {
        return query_cnt (x, n-1, 0, n-1, 0);
    }
    
    void update (int ind, int val) {
        update (ind, val, 0, n-1, 0);
    }
 
private:
    
    vector<int> tree_val;
    vector<int> tree_cnt;
    int n;
    
    int query_sum (int x, int y, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree_val[i];
        
        int m = (l+r) >> 1;
        return (
            query_sum (x, y, l, m, i*2+1) +
            query_sum (x, y, m+1, r, i*2+2)
        );
    }
    
    int query_cnt (int x, int y, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree_cnt[i];
        
        int m = (l+r) >> 1;
        return (
            query_cnt (x, y, l, m, i*2+1) +
            query_cnt (x, y, m+1, r, i*2+2)
        );
    }
    
    void update (int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree_cnt[i] += val;
            tree_val[i] = tree_cnt[i]*l;
            return;
        }
        
        int m = (l+r) >> 1;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);
        
        tree_val[i] = tree_val[i*2+1] + tree_val[i*2+2];
        tree_cnt[i] = tree_cnt[i*2+1] + tree_cnt[i*2+2];
    }
};

class Solution {
    
    int n;
    
    int Count (int q, pii last, SegTree& tree) {
        int sum = tree.query_sum(q);
        int cnt = tree.query_cnt(q);
        int ans = sum - (q-1)*cnt;
                
        int l = last.F, r = last.S;
        if (l >= n || (r-l+1) < q) return ans;
        
        if (r >= n) {
            int can = n-l;
            int has = (r-l+1) - (q-1);
            if (can < has) ans -= (has - can);
        }
        return ans;
    }
    
    void Remove (pii val, set<pii>& all, SegTree& tree) {
        all.erase (val);
        if (val.F >= n) return;
        
        tree.update (val.S-val.F+1, -1);
    }
    
    void Insert (pii val, set<pii>& all, SegTree& tree) {
        all.insert (val);
        if (val.F >= n) return;
        
        tree.update (val.S-val.F+1, 1);
    }
    
    pii GroupContainingX (int ind, set<pii>& all) {
        auto it = all.upper_bound({ind, -1});
        if (it != all.begin()) {
            auto prv = it;
            prv --;
            if (prv->S >= ind) it = prv;
        }
        return *it;
    }
    
    void update (int ind, int val, set<pii>& all, vector<int>& arr, SegTree& tree) {
        if (ind == 2*n-1 || arr[ind] == val) return;
        arr[ind] = val;

        pii with_ind = GroupContainingX (ind, all);
        Remove (with_ind, all, tree);
        int l = with_ind.F, r = with_ind.S;
        
        if (l < ind && r > ind) {
            Insert ({l, ind-1}, all, tree);
            Insert ({ind, ind}, all, tree);
            Insert ({ind+1, r}, all, tree);
            return;
        }
        
        // r == ind || l == ind
        if (l == ind && r != ind) Insert ({l+1, r}, all, tree);
        if (r == ind && l != ind) Insert ({l, r-1}, all, tree);
        
        l = r = ind;
        auto it = all.upper_bound({ind, -1});
        
        vector<pii> to_remove;
        
        auto lft = it, rgt = it;
        while (lft != all.begin()) {
            lft --;
            if (arr[lft->S] == arr[l]) break;
            
            to_remove.push_back(*lft);
            l = lft->F;
        }
        while (rgt != all.end()) {
            if (arr[rgt->F] == arr[r]) break;
            
            to_remove.push_back(*rgt);
            r = rgt->S;
            rgt ++;
        }
        
        for (auto i : to_remove) Remove (i, all, tree);
        Insert ({l, r}, all, tree);
    }
    
public:
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        n = colors.size();
        
        vector<int> arr(2*n);
        for (int j = 0; j < n; j ++) arr[j] = colors[j];
        for (int j = n; j < 2*n; j ++) arr[j] = colors[j-n];
        
        SegTree tree(2*n);
        
        set<pii> all;
        for (int j = 0; j < 2*n-1; j ++) {
            int l = j, r = j+1;
            while (r < 2*n-1 && arr[r] != arr[r-1]) r ++;
            
            Insert ({l, r-1}, all, tree);
            j = r-1;
        }
        
        vector<int> result;
        for (auto q: queries) {   
            if (q[0] == 1) {
                result.push_back(Count(q[1], GroupContainingX (n, all), tree));
                continue;
            } 
            
            int ind = q[1], val = q[2];
            update (ind, val, all, arr, tree);
            update (n+ind, val, all, arr, tree);
        }
        return result;
    }
};