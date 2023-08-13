int help(vector<int>& nums, int x){
        map<int, int> m;
        for(int i = x;i < nums.size();i++){
            m[nums[i]]++;
        }
        int ans = INT_MAX;
        for(int i = 0;i < nums.size() - x;i++){
            auto it = m.lower_bound(nums[i]);
            if(it!=m.end()){
                ans = std::min(ans, abs(nums[i] - it->first));
            }
            if(it!=m.begin()) {
                map<int, int>::iterator ti = std::prev(it, 1);
                ans = std::min(ans, abs(nums[i] - ti->first));
            }
            m[nums[i+x]]--;
            if(m[nums[i+x]] == 0) m.erase(nums[i+x]);
        }
        return ans;
}

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans1 = help(nums, x);
        reverse(nums.begin(), nums.end());
        int ans2 = help(nums, x);
        return std::min(ans1, ans2);
    }
};