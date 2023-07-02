class Solution {
public:
    bool isPrime(int n)
    {
        if(n==1) return false;
        int temp=sqrt(n);
        for(int i=2;i<=temp;i++)
        {
            if(n%i ==0) return false;
        }
        return true;
    }
    vector<vector<int>> findPrimePairs(int n) {
      vector<vector<int>>res;
        int s=n/2;
        for(int i=2;i<=s;i++)
        {
            if(isPrime(i) && isPrime(n-i))
            {
                res.push_back({i,n-i});
            }
        }
        return res;
    }
};