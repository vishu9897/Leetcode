class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
         sort(begin(nums), end(nums));
        int lo = 0;
        int hi = size(nums) - 1;
        int ans = 0;
        for(auto x: nums)
            cout<<x<<" ";
        cout<<endl;        
        while (lo < hi) {
            if (nums[lo] + nums[hi] < target) {
                cout<<lo<<" "<<hi<<endl;
                ans += hi - lo;
                ++lo;
            } else {
                --hi;
            }
        }
        return ans;
    }
};