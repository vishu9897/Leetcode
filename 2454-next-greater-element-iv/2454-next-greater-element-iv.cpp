class Solution {
public:
   vector<int> secondGreaterElement(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> mid(n, vector<int>(0));
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && A[stk.top()] < A[i]) {
            mid[i].push_back(stk.top());
            stk.pop();
        }
        stk.push(i);
    }
    priority_queue<vector<int>> pq;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        while(pq.size() && -pq.top()[0] < A[i]) {
            ans[pq.top()[1]] = A[i];
            pq.pop();
        }
        for (int& j: mid[i])
            pq.push({-A[j], j});
    }
    return ans;
}
};