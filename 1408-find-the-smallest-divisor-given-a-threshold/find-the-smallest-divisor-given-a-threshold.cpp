class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=INT_MIN,ans;
        for(auto x:nums) high = max(high,x);
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            int re=0;
            for(auto x:nums)
            {
                re += ceil((double)x/(double)mid);
            }
            if(re<=threshold) {
                ans= min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};