void operator+=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        a[i] += b[i];
}

void operator-=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        a[i] -= b[i];
}

bool operator<(const vector<int> &a, const int &n) {
    for (int i : a)
        if (i < n)
            return true;
    return false;
}
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
    if (needs < 0)
        return INT_MAX;

    int m = inner_product(needs.begin(), needs.end(), price.begin(), cost);
    cout<<m<<endl;
    for (auto &offer : special) {
        if (cost + offer.back() >= m) // pruning
            continue;
        needs -= offer;
        m = min(m, shoppingOffers(price, special, needs, cost + offer.back()));
        needs += offer;
    }

    return m;
}
};