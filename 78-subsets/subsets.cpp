class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int> &nums,long long num)
    {
        int n=nums.size();
        while(num--)
        {
            vector<int> ans;
            for(int i=0;i<n;i++){
                if(num & (1<<i)){
                    ans.push_back(nums[i]);
                }
            }
            res.push_back(ans);
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        long long num= 1<<n;
        solve(res,nums,num);
        
        return res;
    }
};