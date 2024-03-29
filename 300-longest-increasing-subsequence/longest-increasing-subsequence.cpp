class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0 || res[res.size()-1]<nums[i])
                res.push_back(nums[i]);
            else
            {
                int ind= lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[ind]=nums[i];
            }
        }
        return res.size();

    }
};