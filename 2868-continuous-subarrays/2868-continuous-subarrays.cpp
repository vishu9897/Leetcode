class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        map<int, int> map;
        int i = 0, j = 0;
        while (j < n) {
            map[nums[j]]++;
            while (map.size() > 1 && map.rbegin()->first - map.begin()->first > 2) {
                map[nums[i]]--;
                if (map[nums[i]] == 0) {
                    map.erase(nums[i]);
                }
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};