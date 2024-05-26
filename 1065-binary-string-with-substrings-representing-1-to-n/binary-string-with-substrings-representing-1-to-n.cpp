class Solution {
public:
        bool queryString(string S, int N) {
        for (int i = N; i > N / 2;  --i) {
            string b = bitset<32>(i).to_string();
            if (S.find(b.substr(b.find("1"))) == string::npos)
                return false;
        }
        return true;
    }
};