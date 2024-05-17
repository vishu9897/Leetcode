class Solution {
public:
    void solve(vector<vector<int>> &res,int index,vector<int> &nums,vector<int> ans)
    {
        if(index>=nums.size())
        {
            res.push_back(ans);
            return;
        }
        
        ans.push_back(nums[index]);
        solve(res,index+1,nums,ans);
        ans.pop_back();
        solve(res,index+1,nums,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        solve(res,0,nums,ans);
        return res;
    }
};