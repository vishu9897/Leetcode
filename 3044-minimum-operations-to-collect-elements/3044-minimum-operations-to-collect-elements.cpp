class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size(),ans=INT_MAX;
        vector<int> freq(k+1);
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=k)
                freq[nums[i]]=i;
        }
        for(int i=1;i<=k;i++)
        {
            ans=min(ans,freq[i]);
        }
        // cout<<endl;
        return n-ans;
    }
};