class Solution {
public:
    string oddString(vector<string>& ws) {
    for (int j = 0; j + 1 < ws[0].size(); ++j) {
        map<int, vector<int>> m;
        for (int i = 0; i < ws.size(); ++i)
            m[ws[i][j + 1] - ws[i][j]].push_back(i);
        if (m.size() == 2)
        {
            for(auto x: m)
            {
                if(x.second.size()==1)
                    return ws[x.second[0]];
            }
            // cout<<endl;
            // cout<<next(begin(m))->second.size()<<" "<<next(begin(m))->second.back()<<endl;
            // return ws[begin(m)->second.size() == 1 ? begin(m)->second.back() : next(begin(m))->second.back()];
        }
    }
    return ws[0];
}
};