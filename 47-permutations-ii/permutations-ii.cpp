class Solution {
public:
    void solve(vector<int> nums,int index,vector<vector<int>> &res)
    {
        if(index==nums.size())
        {
            res.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++)
        {
            if(i!=index&& nums[i] ==nums[index]) continue;
            swap(nums[index],nums[i]);
            solve(nums,index+1,res);
        }
    }    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        solve(nums,0,res);
        return res;
    }
};