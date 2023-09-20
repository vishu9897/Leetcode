class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);
        int low=1,high=nums.size()-2;
        while(low<=high)
        {
            int mid= low + (high -low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid+1] <nums[mid]) return mid-1;
            else if(nums[mid]>=nums[mid-1]) low=mid+1;
            else high=mid-1;
        }
        return 0;
    }
};