class Solution {
public:
    void solve(set<vector<int>> &res,int index,vector<int> &nums,vector<int> ans)
    {
        if(index>=nums.size())
        {
            res.insert(ans);
        }
        for(int i=index;i<nums.size();i++)
        {
            ans.push_back(nums[i]);
            solve(res,i+1,nums,ans);
            ans.pop_back();
            solve(res,i+1,nums,ans);
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> ans;
        solve(res,0,nums,ans);
        vector<vector<int>> finalRes;
        for(auto x: res)
        {
            finalRes.push_back(x);
        }
        return finalRes;
    }
};