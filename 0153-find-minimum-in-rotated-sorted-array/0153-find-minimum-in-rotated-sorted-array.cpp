class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        if(nums.size()==1) return nums[0];
        if(nums[0] < nums[right]) return nums[0];
        while(right>=left)
        {
            int mid=left + (right-left)/2;
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            if(nums[mid] < nums[mid-1]) return nums[mid];
            if(nums[mid] > nums[0])
                left=mid+1;
            else
                right=mid-1;
        }
        return INT_MAX;
    }
};