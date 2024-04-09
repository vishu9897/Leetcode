class Solution {
public:
    int solve(vector<int> &nums,int k)
    {
        if(k<=0) return 0;
        unordered_map<int,int> mp;
        int left=0,right=0,cnt=0,n=nums.size();
        while(right<n)
        {
            mp[nums[right]]++;
            while(mp.size()>k)
            {
                mp[nums[left]]--;
                if(mp[nums[left]] <= 0) mp.erase(nums[left]);
                left++;
            }
            cnt = cnt + (right-left+1);
            right++;
        }

        return cnt;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};