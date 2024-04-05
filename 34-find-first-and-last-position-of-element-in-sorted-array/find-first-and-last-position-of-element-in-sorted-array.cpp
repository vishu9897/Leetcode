class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mini=-1,maxi=-1;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(nums[mid] >= target)
            {
                high=mid-1;
                if(nums[mid]==target) mini=mid;
            }
            else low= mid+1;
        }
        low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(nums[mid] <= target)
            {
                low=mid+1;
                if(nums[mid]==target) maxi=mid;
            }
            else high= mid-1;
        }
        return {mini,maxi};
    }
};