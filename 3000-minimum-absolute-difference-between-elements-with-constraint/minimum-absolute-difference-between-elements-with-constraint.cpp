class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;
        multiset<int> s;
        for(int i = x; i < nums.size(); ++i){
            s.insert(nums[i-x]);
            auto it = s.lower_bound(nums[i]);
            int ans1;
            // if(i==4) cout<<"it "<<*it<<endl;
            if(it != s.end())
            {
                // cout<<"first ";
                ans = min(ans, abs(nums[i] - *it));
                ans1=*it;
            } 
            if(it!=s.begin())
            {
                ans = min(ans, abs(nums[i] - *prev(it)));
                // cout<<"second ";
                ans1=*prev(it);
            } 
            // cout<<i<<" "<<nums[i]<<" "<<ans1<<endl;
        }
        // for(auto x:s) cout<<x<<" ";
        return ans;
    }
};