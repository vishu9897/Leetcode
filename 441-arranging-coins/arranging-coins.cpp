class Solution {
public:
    int arrangeCoins(int n) {
        int low=1,high=n;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            
            long long cnt=(long long)(mid * (mid+1))/2;
            // cout<<mid<<" "<<cnt<<endl;
            if(cnt==n) return mid;
            if(cnt>n)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return high;
    }
};