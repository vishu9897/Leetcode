#define ll long long

ll dp[50][50][2];

ll find(int pos, int stat, int jump, int back, vector<ll> &exp, int k)
{
    if(pos > k+1) // no possible way to attain k once step number exceeds k + 1
        return 0;
    
    if(dp[jump][back][stat] != -1)
        return dp[jump][back][stat]; 
    
    ll ans = 0;
    
    if(pos == k) // dont end the recursion here as we may still reach k even after this
        ++ans; 

    if(stat == 1)
    {
        ans += find(pos-1, 0, jump, back+1, exp, k); // backstep
    }
    ans += find(pos+exp[jump], 1, jump+1, back, exp, k);
    
    return dp[jump][back][stat] = ans;
}


class Solution {
public:
    int waysToReachStair(int k) {
            
        memset(dp, -1, sizeof(dp));
        vector<ll> exp(33,0);
        
        for(int i=0; i<33; ++i) // creating a pre-computed array containing powers of 2 to speed up the calculation.
            exp[i] = pow(2, i);
        
        ll ans = find(1, 1, 0, 0, exp, k);  
            
        return ans;
    }
};