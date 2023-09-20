class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int mini=INT_MAX,maxi=-1;
        while(low <= high)
        {
            int mid= low + (high-low)/2;
            if(nums[mid]==target)
            {
                mini=min(mini,mid);
                high=mid-1;    
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        low=0,high=nums.size()-1;
        while(low <= high)
        {
            int mid= low + (high-low)/2;
            if(nums[mid]==target)
            {
                maxi=max(maxi,mid);
                low=mid+1;    
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        } 
        if(mini==INT_MAX) mini=-1;
        return {mini,maxi};   
    }
};