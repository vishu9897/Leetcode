class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower=-1,upper=-1,low=0,high=nums.size()-1;

        while(low <= high)
        {
            int mid= low + (high - low)/2;
            if(nums[mid] == target){
                lower=mid;
                high=mid-1;
            }
            else if(nums[mid] < target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid= low + (high - low)/2;
            if(nums[mid]==target)
            {
                upper=mid;
                low=mid+1;
            }
            else if(nums[mid] < target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return {lower,upper}; 
    }
};