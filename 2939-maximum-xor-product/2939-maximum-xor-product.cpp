class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
            int mod = 1000000007;
    if (n)
        for (long long bt = 1LL << (n - 1); bt > 0; bt >>= 1)
        {
            if ((min(a,b) & bt) == 0) {
                a ^= bt;
                b ^= bt;
            }
        }
    return a % mod * (b % mod) % mod;
        
    }
};