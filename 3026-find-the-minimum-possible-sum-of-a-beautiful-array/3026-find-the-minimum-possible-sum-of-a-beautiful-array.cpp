class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long long tem=target/2,i=1,sum=0;
        int mod=1e9+7;
        cout<<tem<<endl;
        if(n>tem)
        {
            cout<<n<<" "<<tem<<endl;
            sum = (tem*(tem+1))/2;
            sum=sum%mod;
            i=target;
            for(long long j=tem;j<n;j++)
            {
                sum=(sum%mod + i%mod)%mod;
                i=i%mod+1;
                
            }
        }
        else
        {
            for(i=1;i<=n;i++)
                sum=(sum%mod + i%mod)%mod;
        }
        return sum;
    }
};