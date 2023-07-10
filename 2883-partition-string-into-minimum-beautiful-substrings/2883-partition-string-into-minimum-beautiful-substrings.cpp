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
        // if(s[0]==1) dp[0]=1;
        for(int i=0;i<s.size();i++){
            long long mini=INT_MAX;
            for(int j=s.size()-1;j>=0;j--){
                if(i<j) continue;
                if(isPower(s,i,j)){
                    long long cases;
                    if(j!=0)
                    cases= (long long) 1 + dp[j-1];
                    else
                    cases= (long long)1 ;
                    mini=min(mini,cases);
                    // cout<<i<<" "<<j<<" dp ";
                    // for(int i=0;i<s.size()+2;i++)
                    // {
                    //     cout<<dp[i]<<" ";
                    // }
                    // cout<<endl;
                }
            }
            dp[i]=mini;
        }
        // for(int i=0;i<s.size()+2;i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        long long ans=dp[s.size()-1];
        // return 0;
        return ans>=INT_MAX ? -1 : ans ;
    }
};