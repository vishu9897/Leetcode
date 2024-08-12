class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long mod=1e12+7;
        long long suff=1,pref=1,ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            
            
            pref=(long long) (pref%mod *nums[i]%mod)%mod;
            suff =(long long) (suff%mod*nums[n-i-1]%mod)%mod;
            ans=max(ans,max(pref,suff));
            if(nums[i]==0) pref=1;
            if(nums[n-i-1]==0) suff=1;

        }
        return ans;
    }
};