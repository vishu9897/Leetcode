class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=1,mini=1;
        int ans=INT_MIN;
        for(auto x: nums)
        {
            if(x<0) swap(maxi,mini);
            maxi=max(maxi*x,x);
            mini=min(mini*x,x);
            ans= max(ans,maxi);
        }
        return ans;
    }
};