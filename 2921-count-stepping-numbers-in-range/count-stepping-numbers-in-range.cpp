typedef long long ll;
ll dp[110][2][2][14],mod=1e9+7;

// pos= 110;
// tight= 2;
// last= 11
class Solution {
public: 
    ll solve(string str,int pos=0,int tight=1,int isZero=1,int last=-1,string temp="")
    {
        // cout<<pos<<" "<<last<<" "<<str.size()<<endl;
        if(dp[pos][tight][isZero][last+1]!=-1) return dp[pos][tight][isZero][last+1];
        if(pos==str.size()) {
            // cout<<temp<<endl;
            return 1;
        }
        if(tight==1)
        {
            int cnt=0,tempZero=0;
            for(int i=0;i<=str[pos]-'0';i++)
            {
                tempZero=0;
                if(i==0 && isZero==1) tempZero=1;
                if(last!=-1 && abs(last-i) != 1 && isZero==0) continue;
                if(str[pos]-'0' == i)
                {
                   cnt = (cnt%mod + solve(str,pos+1,1,tempZero,i,temp + to_string(i))%mod)%mod;
                }


                else
                    cnt = (cnt%mod + solve(str,pos+1,0,tempZero,i,temp+ to_string(i))%mod)%mod;
            }
            dp[pos][tight][isZero][last+1]=cnt;
        }
        else
        {
            int cnt=0,tempZero=0;
            for(int i=0;i<=9;i++)
            {
                tempZero=0;
                if(i==0 && isZero==1) tempZero=1;
                if(last!=-1 && abs(last-i) != 1 && isZero==0) continue;
                    cnt = (cnt%mod + solve(str,pos+1,0,tempZero,i,temp+to_string(i))%mod)%mod;
            }
            dp[pos][tight][isZero][last+1]=cnt;
        }
        return dp[pos][tight][isZero][last+1];
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        ll h=solve(high);
        memset(dp,-1,sizeof(dp));
        ll l=solve(low);
        ll ans=h-l;
        ans = (ans+ mod)%mod;
        bool add = true;
        for (int i = 1; i <  low.size(); i++)
            if (abs(low[i] - low[i - 1]) != 1) add = false;
        if (add) ans++;
        ans=ans%mod;

        return ans;
    }
};