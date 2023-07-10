class Solution {
public:
    bool isPower(string s,int start,int k)
    {   
        int num=0,j=0;
        for(int i=start;i>=k;i--)
        {
            int temp=0;
            if(s[i]=='1')
            {
                num=num | 1<<j;
            }
            j++;
        }
        if(s[k]=='0') return false;
        while(num%5==0 && num>1)
        {
            num=num/5;
        }
        return num==1;
    }
    int minimumBeautifulSubstrings(string s) {
        vector<int> dp(s.size()+4,0);
        for(int i=0;i<s.size();i++){
            long long mini=INT_MAX;
            for(int j=s.size()-1;j>=0;j--){
                if(i<j) continue;
                if(isPower(s,i,j)){
                    long long cases;
                    if(j!=0)
                    cases= (long long) 1 + dp[j-1];
                    else
                    cases= 1 ;
                    mini=min(mini,cases);
                }
            }
            dp[i]=mini;
        }
        return dp[s.size()-1]>=INT_MAX ? -1 : dp[s.size()-1] ;
    }
};