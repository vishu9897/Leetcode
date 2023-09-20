class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mini=INT_MAX;
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            mini=min(mini,nums[mid]);
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            if(nums[low]<= nums[mid] && nums[mid]<= nums[high])
                high=mid-1;
            else if(nums[low]>nums[mid]) high=mid-1;
            else low=mid+1;   
        }
        return mini;
    }
};