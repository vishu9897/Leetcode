class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1,high=0,ans=INT_MAX;
        for(auto x:weights)
        {
            high+=x;
        }
        while(low<=high)
        {
            int mid= low + ((high-low)>>2);
            int cnt=1,sum=0;
            // cout<<mid<<"-->";
            for(int i=0;i<weights.size();i++)
            {
                if(mid < weights[i]) cnt+=days;
                if(sum + weights[i] <= mid)
                {
                    sum=weights[i]+sum;
                }
                else
                {
                    cnt++;
                    sum=weights[i];
                }
                // cout<<" "<<i<<" "<<cnt<<" "<<sum<<endl;
            }
            cout<<endl;
            if(cnt<= days)
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};