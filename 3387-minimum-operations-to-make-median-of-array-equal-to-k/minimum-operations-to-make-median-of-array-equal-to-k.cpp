class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid;
        if(n%2 == 0) mid=n/2;
        else mid= n/2;
        for(int i=0;i<nums.size();i++)
        {
            if(i<mid && k<nums[i])
                ans +=  nums[i]-k;
            else if(mid==i && (k<nums[i] || k>nums[i]))
                ans+= abs(nums[i]-k);
            else if(i>mid && k>nums[i])
            {
                ans+= abs(nums[i]-k);
            }
        }
        return ans;
    }
};