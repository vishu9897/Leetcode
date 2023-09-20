class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        while(low<=high)
        {
            mid=low + (high-low)/2;
            cout<<nums[low]<<" "<<nums[mid]<<" "<<nums[high]<<endl;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid] && nums[mid]<=nums[high])
            {
                if(target<nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else if(nums[low]<=target && target<=nums[mid]) high=mid-1;
            else if(nums[mid]<=target && target<= nums[high]) low=mid+1;
            else if(nums[low] > nums[mid]) 
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return -1;
    }
};