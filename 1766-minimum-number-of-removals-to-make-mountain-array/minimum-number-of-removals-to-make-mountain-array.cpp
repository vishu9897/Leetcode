class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size(),maxi=0;
        vector<int> incDp(n,1),decDp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<=i-1;prev++)
            {
                if(nums[i]>nums[prev] && incDp[i] < incDp[prev]+1)
                {
                    incDp[i]=incDp[prev]+1;
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=n-1;prev>i;prev--)
            {
                if(nums[i]>nums[prev] && decDp[i] < decDp[prev]+1)
                {
                    decDp[i]=decDp[prev]+1;
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" -- "<<incDp[i]<<" "<<decDp[i]<<endl;
        // }
        for(int i=0;i<n;i++)
        {
            if(incDp[i]>1 && decDp[i]>1)
            maxi=max(maxi,incDp[i]+decDp[i]);
        }
        // cout<<maxi<<endl;
        return n-maxi+1;
    }
};