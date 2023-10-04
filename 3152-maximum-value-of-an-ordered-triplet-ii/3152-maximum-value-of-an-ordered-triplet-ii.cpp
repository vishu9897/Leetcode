class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size(),pre=nums[0];
        long long ans=LLONG_MIN;
        vector<pair<long long,long long>> vc(n);
        vc[0].first = nums[0]; 
        vc[1].second = nums[n-1];
        for(int i=1;i<n;i++)
        {
            vc[i].first=pre;
            pre=max(nums[i],pre);
        }
        pre=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            vc[i].second=pre;
            pre=max(nums[i],pre);
        }
        for(int i=1;i<n-1;i++)
        {
            
            ans=max(ans,(long long)((vc[i].first-nums[i])*vc[i].second));
        }
        return ans<0?0:ans;

    }
};