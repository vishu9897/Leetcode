class Solution {
public:
    void solve(vector<int> &nums,int low,int high,int &ans)
    {
        if(low>=high) return;
        int mid= low + (high - low)/2;
        if(mid+1 < nums.size())
        {
            if(nums[mid] > nums[mid+1]) ans=nums[mid+1];
        }
        if(mid-1 >= 0)
        {
            if(nums[mid-1] > nums[mid]) ans=nums[mid];
        }
        solve(nums,low,mid-1,ans);
        solve(nums,mid+1,high,ans);
    }
    int findMin(vector<int>& nums) {
        int ans=-1;
        solve(nums,0,nums.size()-1,ans);
        if(ans==-1) return nums[0];
        return ans;
    }
};