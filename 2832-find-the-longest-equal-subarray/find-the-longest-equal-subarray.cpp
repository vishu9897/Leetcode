class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int max_freq=0;
        int low=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            max_freq=max(max_freq,++mp[nums[i]]);
            int tot= i-low+1;
            if(tot-max_freq>k)
            {
                mp[nums[low]]--;
                low++;
            }
            // cout<<i<<" "<<max_freq<<endl;
        }
        return max_freq;
    }
};