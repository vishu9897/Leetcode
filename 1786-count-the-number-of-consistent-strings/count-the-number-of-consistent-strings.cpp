

bool consistent(const string& s, const uint32_t a)
{
        for(auto c: s)
        {
            if((a & (1u << (c - 'a'))) == 0) return false;
        }
        
        return true;
}

class Solution {
public:
    __attribute__((optimize(3)))
    static int countConsistentStrings(const string& allowed, const vector<string>& words) {
        uint32_t a = 0;
        for(auto c: allowed)
        {
            a |= 1u << (c - 'a');
        }
        
        size_t count = 0;
        for(auto& w : words){
            count += consistent(w, a);
        }
        
        return count;
        
    }
};

static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
