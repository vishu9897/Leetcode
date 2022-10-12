class Solution {
public:
   bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen(nums.size());
        for (int n : nums) {
            auto [it, ok] = seen.insert(n);
            if (!ok) {
                return true;
            }
        }
        return false;
     }
};