class Solution {
public:
    int nonSpecialCount(int l, int r) {
        
        int sqrtR=sqrt(r);
        vector<int> prime(sqrtR+1,1);
        int left=0,right=0;
        for(int i=2;i<=sqrtR;i++)
        {
            if(prime[i]==1)
            {
                for(int j=i*i ;j<=sqrtR;j+=i)
                {
                    prime[j]= 0;
                }
            }
        }
        for(int i=2;i<=sqrtR;i++)
        {
            if(prime[i]==1 && i*i<=l-1) left++;
            if(prime[i]==1 && i*i<=r) right++;
        }
        // cout<<left<<" "<<right<<endl;
        return r-l+1 - (right-left);
    }
};