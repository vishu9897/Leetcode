class Solution {
public:
    struct Trie{
    Trie* ch[26] = {};
    void insert(string &s, int i = 0) {
        if (i < s.size()) {
            if (ch[s[i] - 'a'] == nullptr)
                ch[s[i] - 'a'] = new Trie();
            ch[s[i] - 'a']->insert(s, i + 1);
        }
    }
    bool match(string &s, int cnt, int i = 0) {
        if (cnt < 0 || i == s.size())
            return cnt >= 0;
        bool res = false;
        for (int j = 0; j < 26; ++j)
            if (ch[j] != nullptr)
                res |= ch[j]->match(s, cnt - (j != s[i] - 'a'), i + 1);
        return res;
    }
};
vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
    vector<string> res;
    Trie t;
    for (auto &d : dict)
        t.insert(d);
    for (auto &q : queries) {
        if (t.match(q, 2))
            res.push_back(q);
    }
    return res;
}

};