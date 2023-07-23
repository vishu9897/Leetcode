class Solution {
public:
    
    int maxIncreasingGroups(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long total = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            if (total >= ((count+1)*(count+2))/2) ++count;
        }
        return count;
    }
};