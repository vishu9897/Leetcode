class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        for(int i=0;i<=n-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low=i+1, high=n, take=0 - nums[i];
                while(high>low)
                {
                    if(nums[low] + nums[high]==take)
                    {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[low]);
                        ans.push_back(nums[high]);
                        res.push_back(ans);
                        while(low < high && nums[low]==nums[low+1]) low++;
                        while(low < high && nums[high]==nums[high-1]) high--;
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < take) low++;
                    else high--;
                }
            }
        }
        return res;
    }
};