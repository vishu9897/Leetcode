#define ll long long
int mod=1e9+7;
ll dp[25][2][220];
class Solution {
public:
 
    int solve(string num,int pos,int tight,int sum,int min_sum,int max_sum)
    {
        if(pos>=num.size())
        {
            if(min_sum <= sum && sum<=max_sum) return 1;
            return 0;
        }
        if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];
        long long res=0;
        if(tight)
        {
            for(int i=0;i<=num[pos]-'0';i++)
            {
                if(i == num[pos]-'0')
                {
                    res = (res+solve(num,pos+1,1,sum+i,min_sum,max_sum)+mod)%mod;
                }
                else{
                    res = (res+ solve(num,pos+1,0,sum+i,min_sum,max_sum)+mod)%mod;
                }
            }
        }
        else{
            for(int i=0;i<=9;i++)
            {
                
                res = (res+ solve(num,pos+1,0,sum+i,min_sum,max_sum) + mod ) %mod;
            }
        }
        return dp[pos][tight][sum]=res;
    }
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