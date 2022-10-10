class Solution {
public:
    string robotWithString(string s) {
    string p, t;
    int cnt[26] = {}, lo = 0;
    for(auto ch : s)
        ++cnt[ch - 'a'];
    for (auto ch : s) {
        t += ch;
        --cnt[ch - 'a'];    
        while(lo < 26 && cnt[lo] == 0)
            ++lo;
       
        while(!t.empty() && t.back() - 'a' <= lo) {
            p += t.back();
            t.pop_back();
        }
    }
    return p;
}
};