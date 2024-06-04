#define ll long long
ll dp[25][2][220]; 
int mod=1e9+7;
class Solution {
public:
    ll solve(string num,int pos,int tight,int sum,int mini,int maxi)
    {
        if(num.size()<=pos)
        {
            if(mini<=sum && sum<=maxi) return 1;
            return 0;
        }
        if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];
        // if(tight==1)
        // {
        //     ll res=0;
        //     for(int i=0;i<=num[pos]-'0';i++)
        //     {
        //         if(i==num[pos]-'0') res= (res+solve(num,pos+1,1,sum+i,mini,maxi))%mod;
        //         else  {
        //             res=(res + solve(num,pos+1,0,sum+i,mini,maxi))%mod;
        //         }
        //     }
        //     return dp[pos][tight][sum]=res;
        // }
        
        if(tight){
            ll res=0;
            for(int i=0;i<=num[pos]-'0';i++)
            {
                if(i==num[pos]-'0')
                {
                    res= (res+ solve(num,pos+1,1,sum+i,mini,maxi))%mod;
                }
                else{
                    res = (res+ solve(num,pos+1,0,sum+i,mini,maxi))%mod;
                }
            }
            return dp[pos][tight][sum] = res;
        }
        else{
            ll res=0;
            for(int i=0;i<=9;i++)
            {
                
                res= (res + solve(num,pos+1,0,sum+i,mini,maxi))%mod;
            }
            return dp[pos][tight][sum] = res;
        }
    }
    // ll solve(string num,int pos,int tight,int sum,int min_sum,int max_sum)
    // {
    //     if(pos>=num.size())
    //     {
    //         if(sum>= min_sum && sum<=max_sum) {
                
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];
    //     if(tight==1)
    //     {
    //         ll res=0;
    //         for(int i=0;i<=num[pos]-'0';i++)
    //         {
    //             if(i==num[pos]-'0') res= (res+solve(num,pos+1,1,sum+i,min_sum,max_sum))%mod;
    //             else  {
    //                 res=(res + solve(num,pos+1,0,sum+i,min_sum,max_sum))%mod;
    //             }
    //         }
    //         return dp[pos][tight][sum]=res;
    //     }
    //     else{
    //         ll res=0;
    //         for(int i=0;i<=9;i++)
    //         {
    //             res=(res + solve(num,pos+1,0,sum+i,min_sum,max_sum))%mod;
    //         }
    //         return dp[pos][tight][sum]=res;
    //     }
    // }
    string subtractKro(string num1)
    {
        int index=num1.size()-1;
        int carry=0;
        do{
            
            if(num1[index]-'0'==0 && index==0){
                num1.erase(num1.begin()+ index);
            } 
            else if(num1[index]-'0'==0){
                num1[index]= '9';
            } 
            else {
                num1[index]= ((num1[index]-'0')-1) + '0';
                // cout<<num1<<" "<<index<<endl;
                break;
            }
            index--;
        }
        while(true);
        return num1;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int i=num1.size();
        num1=subtractKro(num1);
        memset(dp,-1,sizeof(dp));
        ll sum2=solve(num2,0,1,0,min_sum,max_sum);
        memset(dp,-1,sizeof(dp));
        ll sum1=solve(num1,0,1,0,min_sum,max_sum);
        return ((sum2-sum1)+mod)%mod;
    }
};