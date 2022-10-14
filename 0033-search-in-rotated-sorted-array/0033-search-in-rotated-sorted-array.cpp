class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        if(nums[0]==target) return 0;
        if(nums[nums.size()-1]==target) return nums.size()-1;
        while(right>=left)
        {
            int mid= left + (right-left)/2;
            if(nums[mid]==target) return mid;
            else if(mid-1 >=0 && nums[mid-1]==target) return mid-1;
            else if(mid+1 <nums.size() && nums[mid+1]==target) return mid+1;
            if(nums[0]< nums[mid])
            {
                if(nums[0]<target && nums[mid]>target) right=mid-1;
                else left=mid+1;
            }
            else
            {
                if(nums[0]< target) right=mid-1;
                else if(nums[mid] < target) left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};