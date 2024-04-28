class Solution {
private:
    int dp[12][2][12];
    int solve(vector<string>& digits,string str,int pos,int tight,string s,int prev)
    {
        if(pos==str.size()) {
            if(prev==0) return 0;
            return 1;
        }
        if(dp[pos][tight][prev]!=-1) return dp[pos][tight][prev];
        int count=0;
        if(tight)
        {
            for(int i=0;i<digits.size();i++)
            {
                if(prev != 0 && digits[i][0] - '0'==0) continue; 
                if((str[pos] - '0') < (digits[i][0] - '0')) continue;
                if((str[pos] - '0') == (digits[i][0] - '0'))
                {
                   count += solve(digits,str,pos+1,1,s + digits[i][0],digits[i][0]-'0');
                }
                else
                    count += solve(digits,str,pos+1,0,s + digits[i][0],digits[i][0]-'0');
            }
        }
        else{
            for(int i=0;i<digits.size();i++)
            {
                if(prev != 0 && digits[i][0] - '0'==0) continue; 
                count += solve(digits,str,pos+1,0,s + digits[i][0],digits[i][0]-'0');
            }
        }
        return dp[pos][tight][prev]=count;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string str=to_string(n);
        digits.push_back("0");
        memset(dp,-1,sizeof(dp));
        string s="";
        int count=0;
        return solve(digits,str,0,1,s,0);    
    }
};