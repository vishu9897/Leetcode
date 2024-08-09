class Solution {
public:
    void solve(vector<int>&nums,int mask,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(mask==((1<<nums.size())-1)) {
            ans.push_back(temp);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!(mask & (1<<i))){
                temp.push_back(nums[i]);
                solve(nums,mask|1<<i,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int mask=0;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,mask,ans,temp);
        return ans;
    }
};