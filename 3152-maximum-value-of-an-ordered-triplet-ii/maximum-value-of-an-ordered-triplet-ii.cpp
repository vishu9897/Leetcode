#define ll long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0;
        int maxi = nums[0];
        int maxVal = 0;
        for(int i=1;i<nums.size();i++)
        {
            res= max(res,1LL * maxVal * nums[i]);
            maxVal= max(maxVal,maxi-nums[i]);
            maxi=max(maxi,nums[i]);
        }
        return res;
    }
};