class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low=1,high=1e9,n=nums.size();
        while(low<=high){
            int mid= low + (high-low)/2;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]<=mid)
                {
                    cnt++;
                    i++;
                }
            }
            if(cnt < k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};