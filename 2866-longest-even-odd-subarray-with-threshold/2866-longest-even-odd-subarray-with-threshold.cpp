class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0, i = 1, last = INT_MAX;
        if(nums[0] <= threshold && nums[0] % 2 == 0) last = 0;
        while(i < nums.size()){
            if(nums[i] > threshold || ((nums[i] % 2) == (nums[i-1] % 2)) ){
                ans = max(ans, i - last );
                last = INT_MAX;
            }
            if(last == INT_MAX && nums[i] <= threshold && nums[i] % 2 == 0) last = i;
            i++;
        }
        ans = max(ans, i - last );
        return ans;
    }
};