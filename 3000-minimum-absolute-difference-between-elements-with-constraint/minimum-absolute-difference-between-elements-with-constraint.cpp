class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;
        multiset<int> s;
        for(int i = x; i < nums.size(); ++i){
            s.insert(nums[i-x]);
            auto it = s.lower_bound(nums[i]);
            int ans1;
            if(it != s.end())
            {
                ans = min(ans, abs(nums[i] - *it));
                ans1=*it;
            } 
            if(it!=s.begin())
            {
                ans = min(ans, abs(nums[i] - *prev(it)));
                ans1=*prev(it);
            }
        }
        return ans;
    }
};