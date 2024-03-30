#define ll long long
int dp[12][2][12];
class Solution {
public:
    int solve(string num,int pos=0,int tight=1,int sum=0)
    {
        if(pos>=num.size()) {
            return sum;
        }
        if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];
        int res=0;
        if(tight)
        {
            for(int i=0;i<=num[pos]-'0';i++)
            {
                int temp= i==1 ? 1 : 0;
                if(num[pos]-'0'==i) res += solve(num,pos+1,1,(i==1) ? sum+1 : sum);
                else    res += solve(num,pos+1,0,(i==1) ? sum+1 : sum);
            }
            return dp[pos][tight][sum]=res;
        }
        else
        {
            res=0;
            
            for(int i=0;i<=9;i++)
            {
                int temp= i==1 ? 1 : 0;
                res += solve(num,pos+1,0,(i==1) ? sum+1 : sum);
            }
            return dp[pos][tight][sum]=res;
        }
    }
    int countDigitOne(int n) {
        string num=to_string(n);
        memset(dp,-1,sizeof(dp));

        return solve(num);
    }
};