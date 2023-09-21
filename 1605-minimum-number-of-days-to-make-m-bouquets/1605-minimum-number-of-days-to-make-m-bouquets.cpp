class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1,high=INT_MIN,ans=-1;
        for(auto x:bloomDay) high=max(high,x);
        while(low<=high)
        {
            int mid= low + (high - low)/2;
            int lo=0,tmp=m;
            for(int i=0;i<bloomDay.size();i++)
            {
                if(bloomDay[i]<=mid)
                {
                    if(i-lo+1 == k)
                    {
                        tmp--;
                        lo=i+1;
                    }
                }
                else lo=i+1;
            }
            if(tmp<=0){ high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};